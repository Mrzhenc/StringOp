#!/bin/bash

#need to install yajl
url="https://registry.hub.docker.com/v1/repositories"
imageName=$1

curl -s "${url}/${imageName}/tags" | json_reformat |grep name |awk '{print $2}' | sed -e 's/"//g'
