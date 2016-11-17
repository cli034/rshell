#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw3
make
bin/rshell

test t.cpp
test -e t.cpp
test -f CS100
test -d CS100
[ CS100 ]
[ -e CS100 ]
[ -f CS100 ]
[ -d CS100 ]
(test -e t.cpp && echo hi) && (date || ls)
test -d CS100 && echo hello && echo hi
test CS100 && echo testing && echo hello world
exit

#end of test cases