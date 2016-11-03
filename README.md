COMMAND RSHELL
Authors:
	Chung-Yin Adrian, Li
	Victor Ramos

PROJECT SUMMARY:

This program mimics the behavior of the command shell prompt. It can perform the same ability as the commands used in
/bin, such as ls, date, echo. However, built in functions like cd, help...etc is not implemented in this program. In addition,
this program have implemented its own exig function, so that the program will terminate correctly which user typed in "exit".
The program successfully perform signle line command, multiple line command, exit command, and commented command. Generally,
the systax for input are the same for bash. An example of single line commend will be "echo hello world", then it should
print out "hello world". There are three different types of connectors avaliable for the user in order to perform a multiple line
command, they are ";" "&&" and "||" respectively. If the command is followed by ";", then the next command is always executed;
if the commend is followed by "&&", then the next command will only execute if and only if the first command executed; lastly,
if a command is followed by "||", then the next command will only execute if and only if the first command fails to execute.
Commented command is also a valid input, but it will not perform any action to the program. To exit the program, simply type in
"exit" anywhere in the command then it will exit the program as long as the command is successfully executed.

LIST OF KNOWN BUGS:

- Commands that are built-in to bash will not work (Ex. cd)
- a single line command that is followed by the connecter ";", and with a white space behind will generate segmentation fault

LANGUAGE USED:
- C++
- C
