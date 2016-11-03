#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw2
make
bin/shell

ls;
ls -a
date
echo hello world
exit

#Done, end of test cases
