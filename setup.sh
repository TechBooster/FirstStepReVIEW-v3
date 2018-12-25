#!/bin/bash -eux

git submodule init && git submodule update
rm -rf node_modules
rm -rf vendor/bundle
# --unsafe-perm はrootでの実行時(= docker環境)で必要 非root時の挙動に影響なし
npm install --unsafe-perm
bundle install --path vendor/bundle
