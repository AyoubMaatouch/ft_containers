#!/bin/bash 

imageName="vector:dev"
if [[ "$(docker images -q $imageName)" == "" ]]
then
    echo "Building $imageName"
    docker build -t $imageName .
fi
docker run --rm -it -m 1g -v "/tmp/:$(pwd)" $imageName