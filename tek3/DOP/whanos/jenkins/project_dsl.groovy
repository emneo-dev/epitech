freeStyleJob("Projects/$DISPLAY_NAME") {
  scm {
    git {
      remote {
        url(REPOSITORY_URL)
      }
    }
  }
  triggers {
    scm('* * * * *')
  }
  wrappers {
    preBuildCleanup()
    environmentVariables {
      def name_ident = DISPLAY_NAME.replaceAll(/\W/, '-').toLowerCase()

      env('WHANOS_APP_NAME', name_ident)
      env('WHANOS_APP_IMAGE', "\$WHANOS_REGISTRY/$name_ident")
    }
  }
  steps {
    shell('''\
      #!/bin/bash

      set -eux

      if [[ -f Dockerfile ]]
      then
        sudo docker build . -t $WHANOS_APP_IMAGE
      else
        WHANOS_LANG=""
        [[ -f Makefile ]] && WHANOS_LANG=${WHANOS_LANG}c
        [[ -f app/pom.xml ]] && WHANOS_LANG=${WHANOS_LANG}java
        [[ -f package.json ]] && WHANOS_LANG=${WHANOS_LANG}javascript
        [[ -f requirements.txt ]] && WHANOS_LANG=${WHANOS_LANG}python
        [[ -f app/main.bf ]] && WHANOS_LANG=${WHANOS_LANG}befunge

        if \\
          [[ -n "$WHANOS_LANG" ]] && \\
          [[ -f $JENKINS_HOME/images/$WHANOS_LANG/Dockerfile.standalone ]]
        then
          sudo docker build . \\
            -t $WHANOS_APP_IMAGE \\
            -f $JENKINS_HOME/images/$WHANOS_LANG/Dockerfile.standalone
        else
          echo "Couldn't infer language for $WHANOS_APP_NAME!"
          exit 1
        fi
      fi

      sudo docker push $WHANOS_APP_IMAGE

      if [[ -f whanos.yml ]]
      then
        cat whanos.yml \\
          | config-gen -i $WHANOS_APP_IMAGE -n $WHANOS_APP_NAME \\
          | kubectl apply -f -
      fi
    '''.stripIndent())
  }
}
