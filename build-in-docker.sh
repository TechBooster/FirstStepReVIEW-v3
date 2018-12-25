#!/bin/bash

if ! (test -e node_modules && test -e vendor/bundle); then
  # node_modules と vendor/bundle がなかったらsetup.shを動かして作成する
  # ホスト環境でこれを作成していた場合、噛み合わせが悪い場合があるので手動で消してやり直す必要がある
  docker run -t --rm -v $(pwd):/book vvakame/review /bin/bash -ci "cd /book && ./setup.sh"
fi

# コマンド手打ちで作業したい時は以下の通り /book に pwd がマウントされます
# docker run -i -t -v $(pwd):/book vvakame/review /bin/bash

docker run -t --rm -v $(pwd):/book vvakame/review /bin/bash -ci "cd /book && npm run pdf"
