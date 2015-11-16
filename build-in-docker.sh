#!/bin/bash

set -eu

echo "*How to build*"
echo ""
echo "cd app"
echo "./setup.sh"
echo "npm run pdf"
echo ""

docker run -i -t -v $(pwd):/app vvakame/review /bin/bash
