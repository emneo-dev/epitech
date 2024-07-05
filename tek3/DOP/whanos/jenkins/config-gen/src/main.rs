use std::{collections::BTreeMap, io::Read};

use clap::{crate_version, App, Arg};
use k8s_openapi::{
    api::{
        apps::v1::{Deployment, DeploymentSpec},
        core::v1::{
            Container, ContainerPort, PodSpec, PodTemplateSpec, ResourceRequirements, Service,
            ServicePort, ServiceSpec,
        },
    },
    apimachinery::pkg::apis::meta::v1::{LabelSelector, ObjectMeta},
};
use serde::Deserialize;

fn read_stdin() -> std::io::Result<String> {
    let mut contents = String::new();

    std::io::stdin().read_to_string(&mut contents)?;

    Ok(contents)
}

#[derive(Debug, Deserialize)]
struct WhanosConfig {
    deployment: WhanosDeployment,
}

#[derive(Debug, Deserialize)]
struct WhanosDeployment {
    replicas: Option<i32>,
    resources: Option<ResourceRequirements>,
    ports: Option<Vec<i32>>,
}

#[derive(Debug)]
struct WhanosK8sDeployment {
    deployment: Deployment,
    service: Option<Service>,
}

impl WhanosConfig {
    fn bake(self, image: impl Into<String>, name: impl Into<String>) -> WhanosK8sDeployment {
        let image = image.into();
        let name = name.into();

        let labels = {
            let mut map = BTreeMap::new();
            map.insert("app".to_string(), name.clone());
            map
        };

        WhanosK8sDeployment {
            service: self.deployment.ports.as_ref().map(|ports| Service {
                metadata: ObjectMeta {
                    name: Some(format!("{}-service", name)),
                    ..Default::default()
                },
                spec: Some(ServiceSpec {
                    type_: Some("LoadBalancer".to_string()),
                    selector: Some(labels.clone()),
                    ports: Some(
                        ports
                            .iter()
                            .map(|x| ServicePort {
                                port: *x,
                                ..Default::default()
                            })
                            .collect(),
                    ),
                    ..Default::default()
                }),
                ..Default::default()
            }),
            deployment: Deployment {
                metadata: ObjectMeta {
                    name: Some(format!("{}-deployment", name)),
                    labels: Some(labels.clone()),
                    ..Default::default()
                },
                spec: Some(DeploymentSpec {
                    replicas: self.deployment.replicas.or(Some(1)),
                    selector: LabelSelector {
                        match_labels: Some(labels.clone()),
                        ..Default::default()
                    },
                    template: PodTemplateSpec {
                        metadata: Some(ObjectMeta {
                            labels: Some(labels.clone()),
                            ..Default::default()
                        }),
                        spec: Some(PodSpec {
                            containers: vec![Container {
                                name: name,
                                image: Some(image),
                                resources: self.deployment.resources,
                                ports: self.deployment.ports.map(|ports| {
                                    ports
                                        .into_iter()
                                        .map(|x| ContainerPort {
                                            container_port: x,
                                            ..Default::default()
                                        })
                                        .collect()
                                }),
                                ..Default::default()
                            }],
                            ..Default::default()
                        }),
                        ..Default::default()
                    },
                    ..Default::default()
                }),
                ..Default::default()
            },
        }
    }
}

fn main() -> Result<(), Box<dyn std::error::Error>> {
    let matches = App::new("whanos-deploy-gen")
        .version(crate_version!())
        .author("Nassim G. <nassim.gharbaoui@epitech.eu>")
        .about("Generate a k8s deployment from a Whanos configuration.")
        .arg(
            Arg::with_name("image")
                .short("i")
                .long("image")
                .value_name("IMAGE")
                .help("Sets the image to use")
                .required(true)
                .takes_value(true),
        )
        .arg(
            Arg::with_name("name")
                .short("n")
                .long("name")
                .value_name("NAME")
                .help("Sets the name of the deployment")
                .required(true)
                .takes_value(true),
        )
        .get_matches();

    let image = matches.value_of("image").unwrap();
    let name = matches.value_of("name").unwrap();

    // read config
    let whanos_yml = read_stdin()?;
    let whanos_cfg: WhanosConfig = serde_yaml::from_str(&whanos_yml)?;

    // generate deployment
    let stdout = std::io::stdout();

    let k8s_cfg = whanos_cfg.bake(image, name);
    serde_yaml::to_writer(&stdout, &k8s_cfg.deployment)?;

    if let Some(ref service) = &k8s_cfg.service {
        serde_yaml::to_writer(&stdout, &service)?;
    }

    // write output

    Ok(())
}
