#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

string reading_in_commands(); // read in the user input
void parser(string, vector<char*>&); // breaks up the user input and put in in vector
int find_semi_connector(vector<char*>); // Look for ";" in user input, return how many are found
int find_andand_connector(vector<char*>); // Look for "&&" in user input, return how many are found
int find_barbar_connector(vector<char*>); // Look for "||" in user input, return how many are found
int find_leftParentheses(vector<char*>); // Look for "(" in the user input, return how many are found
int find_rightParentheses(vector<char*>); // Look for ")" in the user input, return how many are found

#endif