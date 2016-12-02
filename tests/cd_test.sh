#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw4
make
bin/shell

cd src
cd - #back to previous directory
cd - #back to src
cd .. #to previous directory
cd src;
date && cd -
echo hello || cd src
cd #back to home
cd - #undo
(cd - && ls)
(cd - || gajeklgj)
cd agkelbsj
cd agjklea || echo hi
cd radom && ls
exit

#end of test cases