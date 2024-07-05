# TWINK usage

This guide will cover the basic aspects of using TWINK.

## Docker and Kubernetes

To get started, you will need to have an up-to-date [Docker
installation][setup-docker] and a [Kubernetes cluster][setup-k8s] available to
deploy your projects.

Verify that everything is working by running the following commands:

```sh
docker info
```

```sh
kubectl version
```

## Running TWINK

TWINK can be deployed using Docker compose:

```sh
docker compose up
```

After all the images are built and the services are running, you should be able
to access the Jenkins interface at [localhost:8080](http://localhost:8080).

## Linking a Project

To link a project, you only need a URL to a Git repository accessible by the
Jenkins instance. See
[Using Credentials](https://github.com/jenkinsci/git-plugin#using-credentials)
on the documentation for the Jenkins Git plugin for more information.

TWINK tries its best to automatically figure out how to build your project. For
example, with a `app/main.bf` file at the root of the repository, TWINK will
containerise it as a Befunge program. Here's a table of the supported languages
and their detection criteria:

| Language   | Detected File      | Build Command                     | Run Command                    |
| ---------- | ------------------ | --------------------------------- | ------------------------------ |
| C          | `Makefile`         | `make`                            | `./compiled-app`               |
| Java       | `app/pom.xml`      | `mvn package`                     | `java -jar app/target/app.jar` |
| JS         | `package.json`     | `npm ci`                          | `node .`                       |
| Python     | `requirements.txt` | `pip install -r requirements.txt` | `python -m app`                |
| Befunge 93 | `app/main.bf`      | N/A                               | `bef app/main.bf`              |

## Custom images

For most projects, you will probably want more control on the building and
running process. That's why TWINK supports custom images by looking for a
`Dockerfile` at the root of the repository. TWINK provides a set of base images
to use as a starting point for each of the supported languages mentioned above:

| Language   | Base Image          |
| ---------- | ------------------- |
| C          | `whanos-c`          |
| Java       | `whanos-java`       |
| JS         | `whanos-javascript` |
| Python     | `whanos-python`     |
| Befunge 93 | `whanos-befunge`    |

For example, to add TypeScript support to your project, you could have a
`Dockerfile` like the following:

```Dockerfile
FROM whanos-javascript
RUN npm install -g typescript@4.4.3
RUN tsc
RUN find . -name "*.ts" -type f -not -path "./node_modules/*" -delete
```

## Deploying a Project

TWINK allows you to easily depoy your project to a Kubernetes cluster. To do so,
add a `whanos.yml` file at the root of your project specifying the desired
configuration:

```yaml
deployment:
  replicas: 3
  resources:
    limits:
      memory: "128M"
    requests:
      memory: "64M"
  ports:
    - 3000
```

Here's a summary of the available options for the `deployment` section:

| Field       | Description                                      |
| ----------- | ------------------------------------------------ |
| `replicas`  | The number of replicas to deploy. Defaults to 1. |
| `resources` | The resources to allocate to the pods.           |
| `ports`     | The ports to expose.                             |

The `resources` section is the same as the `resources` section of the
[Kubernetes specification][k8s-resources].

## Stopping TWINK

If you want to shut TWINK down, you can do so with:

```sh
docker-compose down
```

[setup-docker]: https://docs.docker.com/install/
[setup-k8s]: https://kubernetes.io/docs/setup/
[k8s-resources]:
  https://kubernetes.io/docs/concepts/configuration/manage-resources-containers/#resource-requests-and-limits-of-pod-and-container
