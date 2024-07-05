folder('Whanos base images') {
  displayName('Whanos base images')
  description('Base images for supported languages.')
}

folder('Projects') {
  displayName('Projects')
  description('Projects to be built.')
}

freeStyleJob('Whanos base images/whanos-javascript') {
  customWorkspace('$JENKINS_HOME/images')
  triggers {
    upstream('Build all base images')
  }
  parameters {
    stringParam {
      name('IMAGE_NAME')
      defaultValue('whanos-javascript')
      description('Name of the image to be built.')
      trim(true)
    }
    stringParam {
      name('DOCKERFILE_PATH')
      defaultValue('javascript/Dockerfile.base')
      description('Path to the Dockerfile of the base image.')
      trim(true)
    }
  }
  steps {
    shell('sudo docker build . -t $IMAGE_NAME -f $DOCKERFILE_PATH')
  }
}

freeStyleJob('Whanos base images/whanos-befunge') {
  customWorkspace('$JENKINS_HOME/images')
  triggers {
    upstream('Build all base images')
  }
  parameters {
    stringParam {
      name('IMAGE_NAME')
      defaultValue('whanos-befunge')
      description('Name of the image to be built.')
      trim(true)
    }
    stringParam {
      name('DOCKERFILE_PATH')
      defaultValue('befunge/Dockerfile.base')
      description('Path to the Dockerfile of the base image.')
      trim(true)
    }
  }
  steps {
    shell('sudo docker build . -t $IMAGE_NAME -f $DOCKERFILE_PATH')
  }
}

freeStyleJob('Whanos base images/whanos-c') {
  customWorkspace('$JENKINS_HOME/images')
  triggers {
    upstream('Build all base images')
  }
  parameters {
    stringParam {
      name('IMAGE_NAME')
      defaultValue('whanos-c')
      description('Name of the image to be built.')
      trim(true)
    }
    stringParam {
      name('DOCKERFILE_PATH')
      defaultValue('c/Dockerfile.base')
      description('Path to the Dockerfile of the base image.')
      trim(true)
    }
  }
  steps {
    shell('sudo docker build . -t $IMAGE_NAME -f $DOCKERFILE_PATH')
  }
}

freeStyleJob('Whanos base images/whanos-java') {
  customWorkspace('$JENKINS_HOME/images')
  triggers {
    upstream('Build all base images')
  }
  parameters {
    stringParam {
      name('IMAGE_NAME')
      defaultValue('whanos-java')
      description('Name of the image to be built.')
      trim(true)
    }
    stringParam {
      name('DOCKERFILE_PATH')
      defaultValue('java/Dockerfile.base')
      description('Path to the Dockerfile of the base image.')
      trim(true)
    }
  }
  steps {
    shell('sudo docker build . -t $IMAGE_NAME -f $DOCKERFILE_PATH')
  }
}

freeStyleJob('Whanos base images/whanos-python') {
  customWorkspace('$JENKINS_HOME/images')
  triggers {
    upstream('Build all base images')
  }
  parameters {
    stringParam {
      name('IMAGE_NAME')
      defaultValue('whanos-python')
      description('Name of the image to be built.')
      trim(true)
    }
    stringParam {
      name('DOCKERFILE_PATH')
      defaultValue('python/Dockerfile.base')
      description('Path to the Dockerfile of the base image.')
      trim(true)
    }
  }
  steps {
    shell('sudo docker build . -t $IMAGE_NAME -f $DOCKERFILE_PATH')
  }
}

freeStyleJob('Build all base images') {}

freeStyleJob('link-project') {
  customWorkspace('$JENKINS_HOME')
  parameters {
    stringParam {
      name('REPOSITORY_URL')
      defaultValue('')
      description('URL of the project\'s Git repository.')
      trim(true)
    }
    stringParam {
      name('DISPLAY_NAME')
      defaultValue('')
      description('Display name for the created job.')
      trim(true)
    }
  }
  steps {
    dsl(['project_dsl.groovy'])
  }
}
