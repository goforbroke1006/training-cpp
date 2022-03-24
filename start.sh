#!/bin/bash

set -e

echo "Remove solution from random file!"
echo "Be ready to fix it!"

rand_filename=$(find ./ -type f -iregex '.*\.\(h\|cpp\)' -exec grep {} -e '// SOLUTION' -l \; | sort -R | head -n 1)

chmod +x ./start.py
python3 ./start.py "${rand_filename}"
echo "Broken file: ${rand_filename}"
