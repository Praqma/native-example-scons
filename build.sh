#!/usr/bin/env bash

set -x

export DEBIAN_FRONTEND=noninteractive
export WORKSPACE_DIR=/workspace

if [ "$PWD" != "$WORKSPACE_DIR" ]; then
  # Control will enter here if $DIRECTORY doesn't exists.
  echo "Go to /workspace directory before running this script."
  exit 1
fi

git submodule update --init --force

scons

${WORKSPACE_DIR}/out/bin/main

${WORKSPACE_DIR}/out/bin/test
