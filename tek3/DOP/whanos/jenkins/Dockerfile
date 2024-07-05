FROM rust AS config-gen-builder
WORKDIR /src
COPY jenkins/config-gen .
RUN cargo install --path . --locked

FROM jenkins/jenkins:lts

WORKDIR $JENKINS_HOME

USER root
# Install docker and sudo
RUN apt-get update && apt-get install -y docker.io sudo
RUN echo "jenkins ALL=NOPASSWD: ALL" >> /etc/sudoers
# Install kubectl
RUN curl -LO \
    "https://dl.k8s.io/release/$(\
    curl -Ls https://dl.k8s.io/release/stable.txt \
    )/bin/linux/amd64/kubectl" \
    && install -o root -g root -m 0755 kubectl /usr/local/bin/kubectl
# Install Jenkins plugins
COPY --chown=jenkins:jenkins \
    jenkins/plugins.txt \
    /usr/share/jenkins/ref/plugins.txt
RUN /usr/local/bin/install-plugins.sh < /usr/share/jenkins/ref/plugins.txt
# Install config-gen
COPY --from=config-gen-builder \
    /usr/local/cargo/bin/config-gen \
    /usr/local/bin/config-gen

USER jenkins
RUN echo 2.0 > /usr/share/jenkins/ref/jenkins.install.UpgradeWizard.state
COPY \
    [ "jenkins/casc.yml" \
    , "jenkins/job_dsl.groovy" \
    , "jenkins/project_dsl.groovy" \
    , "./" \
    ]
COPY images images
ENV CASC_JENKINS_CONFIG $JENKINS_HOME/casc.yml
ENV USER_ADMIN_PASSWORD admin
EXPOSE 8080
