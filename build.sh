# This causes the script to stop as soon as an error is encountered
set -e

cmake -B build .
make -C build
