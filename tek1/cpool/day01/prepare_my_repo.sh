#!/bin/bash

blih -u alexandre.flion@epitech.eu repository create $1
blih -u alexandre.flion@epitech.eu repository setacl $1 ramassage-tek r
blih -u alexandre.flion@epitech.eu repository getacl $1
