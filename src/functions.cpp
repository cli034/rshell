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
#include "functions.h"



using namespace std;


string reading_in_commands() //read in the user input
{
    string commands;
    getline(cin,commands);
    if (commands.empty())
    {
         return "";
    }
    return commands;
}

void parser(string a, vector<char*> &v) //this break up the user input put it in vector 
{
    char * array = new char[a.size()+1];    //array for space
    char * array2 = new char[a.size()*2]; //array for ;
    char * array3 = new char[a.size()*2]; //array for &&
    char * array4 = new char[a.size()*2]; //array for ||
    strcpy(array, a.c_str());
    //multple array to take care of the diffrent connector the input can have 
    
    char* comment; //finding comments #
    comment = strtok(array, "#");
    if(comment == NULL)
    {
        //DO NOTHING because these are comments
    }
    else
    {
        array = comment; //set the the uncommented section to the array
    }

    
    char* connector1 = (char*)";";
    char* connector2 = (char*)"&&";
    char* connector3 = (char*)"||";
    
    //this first looks for the the ; connector
    char* block;
    block = strtok(array, ";");
    int i = 0;
    while(block != NULL)
    {
        
        if(i == 0)
        {
            strcpy(array2, block);
            strcat(array2, " ");
            strcat(array2, connector1);
            strcat(array2, " ");
            block = strtok(NULL, ";");
        }
        else
        {
            strcat(array2, block);
            strcat(array2, " ");
            strcat(array2, connector1);
            strcat(array2, " ");
            block = strtok(NULL, ";");
        }
        i++;
    }
    
    //this is needed becasue it add an extra connector and spaces 
    string a1(array2);
    a1.erase(a1.size()-3, 3);
    strcpy(array2, a1.c_str());

    
    //===================================================================
    //this then looks for the && connector
    char* block1;
    block1 = strtok(array2, "&&");
    int i1 = 0;
    while(block1 != NULL)
    {
        if(i1 == 0)
        {
            strcpy(array3, block1);
            strcat(array3, " ");
            strcat(array3, connector2);
            strcat(array3, " ");
            block1 = strtok(NULL, "&&");
        }
        else
        {
            strcat(array3, block1);
            strcat(array3, " ");
            strcat(array3, connector2);
            strcat(array3, " ");
            block1 = strtok(NULL, "&&");
        }
        i1++;
    }
    //this is needed becasue it add an extra connector and spaces
    string a2(array3);
    a2.erase(a2.size()-3, 3);
    strcpy(array3, a2.c_str());


    //=========================================================================
    //this then looks for the || connector
    char* block2;
    block2 = strtok(array3, "||");
    int i2 = 0;
    while(block2 != NULL)
    {
        if(i2 == 0)
        {
            strcpy(array4, block2);
            strcat(array4, " ");
            strcat(array4, connector3);
            strcat(array4, " ");
            block2 = strtok(NULL, "||");
        }
        else
        {
            strcat(array4, block2);
            strcat(array4, " ");
            strcat(array4, connector3);
            strcat(array4, " ");
            block2 = strtok(NULL, "||");
        }
        i2++;
    }
    //this is needed becasue it add an extra connector and spaces
    string a3(array4);
    a3.erase(a3.size()-3, 3);
    strcpy(array4, a3.c_str());

    
    //this then looks for the spaces in the input
    //========================================================================
    char* block3;
    block3 = strtok(array4, " ");
    while(block3 != NULL)
    {
        v.push_back(strdup(block3));
        block3 = strtok(NULL, " ");
    }
    v.push_back(NULL);
     
    //========================================================================= 
    
    
    
    
    
    delete[] array;
    delete[] array2;
    delete[] array3;
    delete[] array4;
    //delete the array so no memory leaks are present
    
}

// Look for ";" in user input and return how many are found 
int find_semi_connector(vector<char*> a)
{
    string first_connetor = ";";
    int first_connetor_found = 0;
    for(unsigned int i = 0; i < a.size() - 1; i++)
    {
        if(strcmp(a.at(i),(char*)first_connetor.c_str()) == 0)
        {
            first_connetor_found++;
        }
    }
    return first_connetor_found;
}

// Look for "&&" in user input and return how many are found  
int find_andand_connector(vector<char*> b)
{
    string secound_connetor = "&&";
    int secound_connetor_found = 0;
    for(unsigned int i = 0; i < b.size() - 1; i++)
    {
        if(strcmp(b.at(i),(char*)secound_connetor.c_str()) == 0)
        {
            secound_connetor_found++;
        }
    }
    return secound_connetor_found;
}

// Look for "||" in user input and return how many are found 
int find_barbar_connector(vector<char*> c)
{
    string third_connetor = "||";
    int third_connetor_found = 0;
    for(unsigned int i = 0; i < c.size() - 1; i++)
    {
        if(strcmp(c.at(i),(char*)third_connetor.c_str()) == 0)
        {
            third_connetor_found++;
        }
    }
    return third_connetor_found;
}
