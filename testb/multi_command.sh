#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw2
make
bin/shell

ls -a; ls -l
echo hello; echo hi; date
ls; echo hello || echo yolo
ls -a; echo hello; mkdir test
date; ls; ls
ls -l; ls -a; ls
echo ez; echo ahaha; date && ls -l
echo this is hard; ls
ls -a; echo hello && mkdir test || echo world; git status
exit

#DONE, end of test cases