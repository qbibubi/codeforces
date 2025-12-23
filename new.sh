# !/bin/bash
EDITOR=code

if [ -z "$1" ]; then
  echo "No arguments passed. Script requires a directory name as arugment. (Example: 118a)"
  exit 1
fi

cp -r ./example ./"$1" && cd ./"$1"/ && $EDITOR src/main.cc
