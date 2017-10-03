#!/usr/bin/env bash

# conan remove "*" --src --builds --force
# git clean -dfx && git submodule foreach "git clean -dfx"
# git submodule update --init

docker run --rm --tty --interactive --workdir=/workspace --volume ${PWD}:/workspace praqma/native-scons:latest bash
