#!/bin/sh

git clone http://github.com/yourusername/rshell.git
cd rshell
git checkout hw3
make
bin/rshell

(echo a && echo b)
(date && ls); echo hello
(ls || ls -a)
(date && echo hi) && (ls || echo xp)
(date || echo hi) && (ls && echo xp)
(ls -a && date) || (echo hello || git status)
(test -e t.cpp || echo hi) && (date || ls)
(test -e t.cpp && echo hi) && (date || ls)
(ls && date)
exit

#end of test cases