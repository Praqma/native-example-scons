#!/usr/bin/env bash

set -x

export DEBIAN_FRONTEND=noninteractive
export WORKSPACE_DIR=/workspace

if [ "$PWD" != "$WORKSPACE_DIR" ]; then
  echo "Test helper script to be run inside a container."
  echo "Go to $WORKSPACE_DIR directory before running this script."
  exit 1
fi

git submodule update --init --force

scons

${WORKSPACE_DIR}/out/bin/test