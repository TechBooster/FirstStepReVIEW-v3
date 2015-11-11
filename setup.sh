#!/bin/bash

set -eux

rm -rf node_modules

npm install

curl -L https://github.com/vvakame/prh/raw/master/misc/techbooster.yml > articles/prh.yml
