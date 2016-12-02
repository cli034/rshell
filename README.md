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

The program can also handle the command test with or without flags "-e", "-d", and "-f". "-e" checks if file/directory exists, "-d" checks if the file/directory exists and is a directory, and "-f" checks if the file/directory exists and is a regular file. The program will print out (TRUE) or (FALSE) depending on if the file/directory is found. Using square brackets is an alternative way of using test command. For example, "[ -e file/directory ]" will be a valid input. If no flags are being inputted, the program will set "-e" to a default flag for the command. The features of using parentheses as precedence operators is also implemented in the program, it is used to change the precedence of the returns of commands, connectors, and chain of connectors. For example, "(echo A && echo B) || (echo C && echo D)" the program will execute (echo A && echo B) then decide if it should execute the rest of the commands based on the execution.

New features has been updated to the program. The program can now use the command cd to change directory. For example "cd" to direct to home, "cd -" to switch back and forth of directory, "cd .." to go back to previous dircectory. This command can be used with other connectors and commands such as (echo hello && cd).

LIST OF KNOWN BUGS:

- a single line command that is followed by the connecter ";", and with a white space behind will generate segmentation fault
- any form of single command within a parentheses will not work. (Ex. (echo a))
- more than two connectors within a parentheses will not work. (Ex. (echo a && echo b && echo c))
- putting excessive arguments when using command test or square brackets will not print anything. (Only one argument should be inputted)
- Using parentheses after a command without parenthese will not work properly. (Ex. date; (echo a && echo b) will not print out b)

LANGUAGE USED:
- C++
- C
