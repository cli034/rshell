#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw2
make
bin/shell

#comment itself, shouldn't do anything
ls #test comment
ls; echo hello #another comment
ls -l || echo hello #comment
date; echo yolo; #testing testing
agjeklajgel #invalid command
echo yay it works #it works

exit
