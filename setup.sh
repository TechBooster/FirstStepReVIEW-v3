#!/bin/bash

set -eux

which grunt > /dev/null 2>&1
if [ $? -ne 0 ] ; then
	npm install -g grunt-cli
fi

rm -rf node_modules
npm install

curl -L https://github.com/vvakame/prh/raw/master/misc/techbooster.yml > articles/prh.yml
