#!/bin/bash

set -eux

rm -rf node_modules
# --unsafe-perm はrootでの実行時(= docker環境)で必要 非root時の挙動に影響なし
npm install --unsafe-perm

curl -L https://github.com/vvakame/prh/raw/master/misc/techbooster.yml > articles/prh.yml
