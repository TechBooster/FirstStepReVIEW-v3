#!/bin/bash

if ! (test -e node_modules && test -e vendor/bundle); then
  docker run -t --rm -v $(pwd):/book vvakame/review:2.4 /bin/bash -ci "cd /book && ./setup.sh"
fi

# コマンド手打ちで作業したい時は以下の通り /book に pwd がマウントされます
# docker run -i -t -v $(pwd):/book vvakame/review /bin/bash

docker run -t --rm -v $(pwd):/book vvakame/review /bin/bash -ci "cd /book && npm run pdf"
