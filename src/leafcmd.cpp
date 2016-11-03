#include "leafcmd.h"
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

//constuctor
Cmd::Cmd(vector<char*> a) : cmds_to_execute(a) {}

int Cmd::execute()
{   
    int as = 0; 
    string exit_1 = "exit";
    if(strcmp(cmds_to_execute.at(0),(char*)exit_1.c_str()) == 0)
    {
        exit(0);
    }
    
    int status;
    
    
    pid_t pid = fork();
    if (pid == -1)
    {
        perror("fork");
    }
    if (pid == 0)
    {
        //we are child
        if(execvp(cmds_to_execute[0],cmds_to_execute.data()) == -1)
        {
            
            as = -1;
            perror("exec");
            exit(0);
        }
    }
    if(pid > 0)
    {
        //parent
        if(waitpid(pid, &status, 0) == -1)
        {
            perror("wait");
        }
        
    }
    return as;
}
