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
#include <sys/stat.h>

using namespace std;

//constuctor
Cmd::Cmd(vector<char*> a) : cmds_to_execute(a) {}

int Cmd::execute()
{   
    int as = 0; 
    //int fl = 0; 
    string exit_1 = "exit";
    string test_1 = "test";
    string test_2 = "[";
    string test_3 = "]";
    string flag_1 = "-e";
    string flag_2 = "-f";
    string flag_3 = "-d";
    string cd_1 = "cd";
    string back_1 = "-";
    struct stat buf;
    if(strcmp(cmds_to_execute.at(0),(char*)exit_1.c_str()) == 0)
    {
        exit(0);
    }
    else if(strcmp(cmds_to_execute.at(0),(char*)cd_1.c_str()) == 0)
    {
        if(cmds_to_execute.size() == 3)
        {
            if(strcmp(cmds_to_execute.at(1),(char*)back_1.c_str()) == 0)
            {
                int a = 0;
                char* old = getenv("OLDPWD");
                if(setenv("OLDPWD",getenv("PWD"),1) == -1)
                {
                    perror("setenv");
		    return 1;
                }
                if(setenv("PWD",old,1) == -1)
                {
                    perror("setenv");
		    return 1;
                }
                
                a = chdir(getenv("PWD"));
                if(a == -1)
                {
                    perror("chdir");
		    return 1;
                }
		return 0;
            }
            else
            {
                int a = 0;
                if(setenv("OLDPWD",get_current_dir_name(),1) == -1)
                {
                    perror("setenv");
		    return 1;
                }
                a = chdir(cmds_to_execute.at(1));
                if(a == -1)
                {
                    perror("chdir");
		    return 1;
                }
                else
                {
                    if(setenv("PWD",get_current_dir_name(),1) == -1)
                    {
                        perror("setenv");
			return 1;
                    }
                }
		return 0;
            }
        }
        else if(cmds_to_execute.size() == 2)
        {
            int a = 0;
            if(setenv("OLDPWD",get_current_dir_name(),1) == -1)
            {
                perror("setenv");
		return 1;
            }
            //setenv("PWD",getenv("HOME"),1);
            a = chdir(getenv("HOME"));
            if(a == -1)
            {
                perror("chdir");
		return 1;
            }
            else
            {
                if(setenv("PWD",getenv("HOME"),1) == 1)
                {
                    perror("setenv");
		    return 1;
                }
            }
	    return 0;
        }
    }
    else if(strcmp(cmds_to_execute.at(0),(char*)test_1.c_str()) == 0 || (strcmp(cmds_to_execute.at(0),(char*)test_2.c_str()) == 0 && strcmp(cmds_to_execute.at(cmds_to_execute.size()-2),(char*)test_3.c_str()) == 0))
    {
        if(strcmp(cmds_to_execute.at(0),(char*)test_1.c_str()) == 0)
        {
            if(cmds_to_execute.size() == 3)
            {
                if(stat(cmds_to_execute[1], &buf) == 0)
                {
                    cout << "(TRUE)" << endl;
                    return 0;
                }
                else
                {
                    cout << "(FALSE)" << endl;
                    return 1;
                }
            }
            else if(cmds_to_execute.size() == 4)
            {
                if(stat(cmds_to_execute[2], &buf) == 0)
                {
                    if(strcmp(cmds_to_execute.at(1),(char*)flag_2.c_str()) == 0)//-f flag_2
                    {
                        if(S_ISREG(buf.st_mode))
                        {
                            cout << "(TRUE)" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "(FALSE)" << endl;
                            return 1;
                        }
                    }
                    else if(strcmp(cmds_to_execute.at(1),(char*)flag_3.c_str()) == 0)//-d flag_3
                    {
                        if(S_ISDIR(buf.st_mode))
                        {
                            cout << "(TRUE)" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "(FALSE)" << endl;
                            return 1;
                        }
                    }
                    else if(strcmp(cmds_to_execute.at(1),(char*)flag_1.c_str()) == 0)//-e flag_3
                    {
                        cout << "(TRUE)" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "error the flag entered is not valid" << endl;
                        return 1;
                    }
                    
                }
                else
                {
                    if(!(strcmp(cmds_to_execute.at(1),(char*)flag_1.c_str()) == 0 || strcmp(cmds_to_execute.at(1),(char*)flag_2.c_str()) == 0 || strcmp(cmds_to_execute.at(1),(char*)flag_3.c_str()) == 0))
                    {
                        cout << "error the flag entered is not valid" << endl;
                        return 1;
                    }
                    else
                    {
                        cout << "(FALSE)" << endl;
                        return 1;
                    }
                }
            }
        }
        else if((strcmp(cmds_to_execute.at(0),(char*)test_2.c_str()) == 0 && strcmp(cmds_to_execute.at(cmds_to_execute.size()-2),(char*)test_3.c_str()) == 0))
        {
            if(cmds_to_execute.size() == 4)
            {
                if(stat(cmds_to_execute[1], &buf) == 0)
                {
                    cout << "(TRUE)" << endl;
                    return 0;
                }
                else
                {
                    cout << "(FALSE)" << endl;
                    return 1;
                }
            }
            else if(cmds_to_execute.size() == 5)
            {
                if(stat(cmds_to_execute[2], &buf) == 0)
                {
                    if(strcmp(cmds_to_execute.at(1),(char*)flag_2.c_str()) == 0)//-f flag_2
                    {
                        if(S_ISREG(buf.st_mode))
                        {
                            cout << "(TRUE)" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "(FALSE)" << endl;
                            return 1;
                        }
                    }
                    else if(strcmp(cmds_to_execute.at(1),(char*)flag_3.c_str()) == 0)//-d flag_3
                    {
                        if(S_ISDIR(buf.st_mode))
                        {
                            cout << "(TRUE)" << endl;
                            return 0;
                        }
                        else
                        {
                            cout << "(FALSE)" << endl;
                            return 1;
                        }
                    }
                    else if(strcmp(cmds_to_execute.at(1),(char*)flag_1.c_str()) == 0)//-e flag_3
                    {
                        cout << "(TRUE)" << endl;
                        return 0;
                    }
                    else
                    {
                        cout << "error the flag entered is not valid" << endl;
                        return 1;
                    }
                    
                }
                else
                {
                    if(!(strcmp(cmds_to_execute.at(1),(char*)flag_1.c_str()) == 0 || strcmp(cmds_to_execute.at(1),(char*)flag_2.c_str()) == 0 || strcmp(cmds_to_execute.at(1),(char*)flag_3.c_str()) == 0))
                    {
                        cout << "error the flag entered is not valid" << endl;
                        return 1;
                    }
                    else
                    {
                        cout << "(FALSE)" << endl;
                        return 1;
                    }
                }
            }
        }
    }
    else
    {
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
                perror("exec");
                exit(-1);
            }
        }
        if(pid > 0)
        {
            //parent
            if(waitpid(pid, &status, 0) == -1)
            {
                perror("wait");
            }
            if (WIFEXITED(status))
            {
                 as = WEXITSTATUS(status);
                //cout << as << endl;
            }
            
        }
        return as;
    }
    return 1; 
}
