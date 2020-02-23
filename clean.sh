# executes make clean on all makefiles in this directory
find . -type f -iname "makefile" | grep -vF './makefile' | xargs dirname | xargs -L 1 make clean -C
