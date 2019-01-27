#!/usr/bin/env bash

set -euo pipefail

if [ "$TRAVIS_OS_NAME" == "linux" ]; then
# autotools, automake, make are present in the trusty image
  sudo apt-get install -y \
    imagemagick \
    bc
fi

exit 0
