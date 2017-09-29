#!/usr/bin/env bash

docker build --tag praqma/native-scons:latest --file ${PWD}/Dockerfile ${PWD}
