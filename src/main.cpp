#include <iostream> 
#include <cstdlib>
#include <stdlib.h>

//including the classes
#include "basecmd.h"
#include "leafcmd.h"
#include "connector_composites.h"
#include "functions.h"
#include <cstring>
using namespace std;

int main()
{
    //this is an infinite loop to allow user input, until user type "exit"
    for(;;)
    {
        label:
        // int exit_a = 0;
        cout << "$ ";
        string cmd;
        string exit_2 = "exit";
        cmd = reading_in_commands();
        
        if(cmd.compare(exit_2) == 0)
        {
            cmd.clear();
            
            exit(0);
        }
        
        //this then check is the user just pressed enter it will go back to the begining 
        if(cmd.empty())
        {
            goto label;
        }
        
        vector<char*> cmds; //the vector of commands 
        
        
        parser(cmd, cmds); //commads are then seperated and place into cmd
        
        
        //first find how many ; they are in the vector
        int first_connetor_found = find_semi_connector(cmds);
        //first find how many && they are in the vector
        int secound_connetor_found2 = find_andand_connector(cmds);
        //first find how many || they are in the vector
        int third_connetor_found2 = find_barbar_connector(cmds);
        // find how many ( they are in the vector
        int leftParentheses_found2 = find_leftParentheses(cmds);
        // find how many ) they are in the vector
        int rightParentheses_found2 = find_rightParentheses(cmds);
        
        string first_connetor = ";";
        
        if(leftParentheses_found2 == 0 && rightParentheses_found2 == 0)
        {
            // checks if this is and solo cmd 
            if(first_connetor_found == 0 && secound_connetor_found2 == 0 && third_connetor_found2 == 0) // and no || and &&
            {
                Cmd* test = new Cmd(cmds);
                test->execute();
                //delete test;
            }
            
            //set it to a 2D vector(matrix) in which it filled in with a vector of char*
            vector<vector<char*> > cmds2;
    
            //check if the there are connector found set up the 2d vector
            if(first_connetor_found != 0 || secound_connetor_found2 != 0 || third_connetor_found2 != 0)
            {
                int x = 0;
                unsigned int i = 0;
                while(x != first_connetor_found + 1)
                {
                    vector<char*> temp;
                    
                    
                    while(strcmp(cmds.at(i),(char*)first_connetor.c_str()) != 0)
                    {
                        temp.push_back(cmds.at(i));
                        i++;
                        if(i == cmds.size() - 1)
                        {
                            i = i - 1;
                            break;
                        }
                    }
                    temp.push_back(NULL);
                    
                    cmds2.push_back(temp);
                    x++;
                    i++;
                    
                }
            }
            
            
            string secound_connetor = "&&";
            string third_connetor = "||";
            //inside the 2d vector look for the || and &&
            for(unsigned q = 0; q < cmds2.size(); q++)
            {
                int secound_connetor_found = find_andand_connector(cmds2.at(q));
                int third_connetor_found = find_barbar_connector(cmds2.at(q));
                
                
                if(secound_connetor_found == 0 && third_connetor_found == 0) // when theres are no connecters found
                {
                    //then it is a single cmd
                    Cmd* test = new Cmd(cmds2.at(q));
                    test->execute();
                    //delete test;
                }
                //===============================================================================================
                else if(secound_connetor_found != 0 && third_connetor_found == 0) // only && found
                {
                    vector<Basecmd*> temp2; //vector of basecmd*
                    vector<int> c; //vector of inters serves as and indicator of || or && 
                    int x = 0;
                    int y = x + 1;
                    int g = 0;
                    unsigned i1 = 0;
                    while(g != secound_connetor_found + 1)
                    {    
                        vector<char*> temp3;
                        while(strcmp(cmds2.at(q).at(i1),(char*)secound_connetor.c_str()) != 0)
                        {
                            temp3.push_back(cmds2.at(q).at(i1));
                            i1++;
                            if(i1 == cmds2.at(q).size() - 1)
                            {
                                i1 = i1 - 1;
                                break;
                            }
                        }
                        temp3.push_back(NULL);
                        
                        if(strcmp(cmds2.at(q).at(i1),(char*)secound_connetor.c_str()) == 0)
                        {
                            
                            c.push_back(0);
                        }
                        
                        Cmd* a = new Cmd(temp3);
                        temp2.push_back(a);
                        
                        Cmd* temp = NULL;
                        a = temp;
                        //delete a;
                        g++;
                        i1++;
                    }
                    
                    //when finished a vector of Basecmd * is created to then be able 
                    //to execute them
                    //also have a vector of integers that either = 0 or 1 to indicate
                    //if there is && or || to be found
                    
                    Basecmd* temp = NULL;
                    for(unsigned i = 0; i < c.size(); i++)
                    {
                        if(i == 0)
                        {
                            if(c.at(0) == 0)
                            {
                                AndAnd* t1 = new AndAnd(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                            else if(c.at(0) == 1)
                            {
                                BarBar* t1 = new BarBar(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                        }
                        else if(i > 0)
                        {
                            if(c.at(i) == 0)
                            {
                                AndAnd* t = new AndAnd(temp, temp2.at(y));
                                
                                temp = t;
                                
                                t = NULL;
                                //delete t;
                            }
                            else if(c.at(i) == 1)
                            {
                                BarBar* t = new BarBar(temp, temp2.at(y));
                                temp = t;
                                t = NULL;
                                //delete t;
                            }
                        }
                        x++;
                        y++;
                    }
                    temp->execute();
                    
                }
                //============================================================================
                else if(secound_connetor_found == 0 && third_connetor_found != 0) // if only || cases are found
                {
                    vector<Basecmd*> temp2;
                    vector<int> c;
                    int g = 0;
                    unsigned i1 = 0;
                    int x = 0;
                    int y = x + 1;
                    
                    while(g != third_connetor_found + 1)
                    {    
                        vector<char*> temp3;
                        while(strcmp(cmds2.at(q).at(i1),(char*)third_connetor.c_str()) != 0)
                        {
                            temp3.push_back(cmds2.at(q).at(i1));
                            i1++;
                            if(i1 == cmds2.at(q).size() - 1)
                            {
                                i1 = i1 - 1;
                                break;
                            }
                        }
                        temp3.push_back(NULL);
                        
                        if(strcmp(cmds2.at(q).at(i1),(char*)third_connetor.c_str()) == 0)
                        {   
    
                            c.push_back(1);
                        }
    
    
                        Cmd* a = new Cmd(temp3);
                        temp2.push_back(a);
                        
                        Cmd* temp = NULL;
                        a = temp;
                        //delete a;
                        g++;
                        i1++;
                    }
                    
                    //when finished a vector of Basecmd * is created to then be able 
                    //to execute them
                    //also have a vector of integers that either = 0 or 1 to indicate
                    //if there is && or || to be found
                    
                    Basecmd* temp = NULL;
                    for(unsigned i = 0; i < c.size(); i++)
                    {
                        if(i == 0)
                        {
                            if(c.at(0) == 0)
                            {
                                AndAnd* t1 = new AndAnd(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                            else if(c.at(0) == 1)
                            {
                                BarBar* t1 = new BarBar(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                        }
                        else if(i > 0)
                        {
                            if(c.at(i) == 0)
                            {
                                AndAnd* t = new AndAnd(temp, temp2.at(y));
                                temp = t;
                                t = NULL;
                                //delete t;
                            }
                            else if(c.at(i) == 1)
                            {
                                BarBar* t = new BarBar(temp, temp2.at(y));
                                temp = t;
                                t = NULL;
                                //delete t;
                            }
                        }
                        x++;
                        y++;
                    }
                    temp->execute();
                    
                    
                }
                //======================================================================================
                else if(secound_connetor_found != 0 && third_connetor_found != 0) // both && || found
                {
                    vector<Basecmd*> temp2;
                    vector<int> c;
                    int g = 0;
                    unsigned i2 = 0;
                    int x = 0;
                    int y = x + 1;
                    while(g != third_connetor_found + secound_connetor_found + 1)
                    {    
                        
                        vector<char*> temp3;
                        while(  !((strcmp(cmds2.at(q).at(i2),(char*)third_connetor.c_str()) == 0) || (strcmp(cmds2.at(q).at(i2),(char*)secound_connetor.c_str()) == 0))  )
                        {
                            temp3.push_back(cmds2.at(q).at(i2));
                            ++i2;
                            if(i2 == cmds2.at(q).size() - 1)
                            {
                                i2 = i2 - 1;
                                break;
                            }
                        }
                        temp3.push_back(NULL);
                        
                        if(strcmp(cmds2.at(q).at(i2),(char*)third_connetor.c_str()) == 0)
                        {   
                            c.push_back(1);
                        }
                        if(strcmp(cmds2.at(q).at(i2),(char*)secound_connetor.c_str()) == 0)
                        {
                            c.push_back(0);
                        }
                        
                        Cmd* a = new Cmd(temp3);
                        temp2.push_back(a);
                        
                        Cmd* temp = NULL;
                        a = temp;
                        //delete a;
                        //delete a;
                        ++g;
                        ++i2;
                        
                    }
                    
                    //when finished a vector of Basecmd * is created to then be able 
                    //to execute them
                    //also have a vector of integers that either = 0 or 1 to indicate
                    //if there is && or || to be found
    
                    Basecmd* temp = NULL;
                    for(unsigned i = 0; i < c.size(); i++)
                    {
                        if(i == 0)
                        {
                            if(c.at(0) == 0)
                            {
                                AndAnd* t1 = new AndAnd(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                            else if(c.at(0) == 1)
                            {
                                BarBar* t1 = new BarBar(temp2.at(0), temp2.at(1));
                                temp = t1;
                                t1 = NULL;
                                //delete t1;
                            }
                        }
                        else if(i > 0)
                        {
                            if(c.at(i) == 0)
                            {
                                AndAnd* t = new AndAnd(temp, temp2.at(y));
                                temp = t;
                                t = NULL;
                                //delete t;
                            }
                            else if(c.at(i) == 1)
                            {
                                BarBar* t = new BarBar(temp, temp2.at(y));
                                temp = t;
                                t = NULL;
                                //delete t;
                            }
                        }
                        x++;
                        y++;
                    }
                    temp->execute();
                    
                    
                }
                
            }
            
        }
        else
        {
            string connector1_1 = ";";
            string connector2_1 = "&&";
            string connector3_1 = "||";
            string leftParentheses_1 = "(";
            string rightParentheses_1 = ")";
            //char* connector1_1 = (char*)";";
            //char* connector2_1 = (char*)"&&";
            //char* connector3_1 = (char*)"||";
            //char* leftParentheses_1 = (char*)"(";
            //char* rightParentheses_1 = (char*)")";
            vector<char*> temp_1;
            vector<vector<char*> > cmd_1;
            vector<Basecmd*> basecmd_1;
            Basecmd* alldone = NULL;
            int flag1 = 0;
            int flag2 = 0;
            int flag3 = 0; 
            int flag4 = 0;
            int flag5 = 0;
            int flag6 = 0; 
            
            
            for(unsigned i = 0; i < cmds.size() - 1; i++)
            {
                if(strcmp(cmds.at(i),(char*)rightParentheses_1.c_str()) != 0 && strcmp(cmds.at(i),(char*)leftParentheses_1.c_str()) != 0)
                {
                    //cout << cmds.at(i) << endl;
                    if(strcmp(cmds.at(i),(char*)connector1_1.c_str()) == 0)
                    {
                        if(strcmp(cmds.at(i - 1),(char*)rightParentheses_1.c_str()) == 0)
                        {
                            ++flag6;
                        }
                        else
                        {
                            Basecmd * temp1_1 = NULL;
                            flag1++;
                            temp_1.push_back(NULL);
                            cmd_1.push_back(temp_1);
                            Cmd * a = new Cmd(temp_1);
                            temp1_1 = a;
                            basecmd_1.push_back(temp1_1);
                            a = NULL;
                            //delete a; 
                            temp_1.clear();
                        }
                    }
                    else if(strcmp(cmds.at(i),(char*)connector2_1.c_str()) == 0)
                    {
                        if(strcmp(cmds.at(i - 1),(char*)rightParentheses_1.c_str()) == 0)
                        {
                            ++flag4;
                        }
                        else
                        {
                            Basecmd * temp1_2 = NULL;
                            flag2++;
                            temp_1.push_back(NULL);
                            cmd_1.push_back(temp_1);
                            Cmd * b = new Cmd(temp_1);
                            temp1_2 = b;
                            basecmd_1.push_back(temp1_2);
                            b = NULL;
                            //delete b; 
                            temp_1.clear();
                        }
                    }
                    else if(strcmp(cmds.at(i),(char*)connector3_1.c_str()) == 0)
                    {
                        if(strcmp(cmds.at(i - 1),(char*)rightParentheses_1.c_str()) == 0)
                        {
                            ++flag5;
                        }
                        else
                        {
                            Basecmd * temp1_3 = NULL;
                            flag3++;
                            temp_1.push_back(NULL);
                            cmd_1.push_back(temp_1);
                            Cmd * c = new Cmd(temp_1);
                            temp1_3 = c;
                            basecmd_1.push_back(temp1_3);
                            c = NULL;
                            //delete c; 
                            temp_1.clear();
                        }
                    }
                    else
                    {
                        temp_1.push_back(cmds.at(i));
                    }
                }
                else if(strcmp(cmds.at(i),(char*)rightParentheses_1.c_str()) == 0)
                {
                    //cout << "2" << endl;
                    Basecmd * temp1_4 = NULL;
                    temp_1.push_back(NULL);
                    cmd_1.push_back(temp_1);
                    Cmd * d = new Cmd(temp_1);
                    temp1_4 = d;
                    basecmd_1.push_back(temp1_4);
                    d = NULL;
                    //delete d;
                    //temp_1.clear();
                    
                    if(flag1 != 0)
                    {
                        if(flag1 == 1)
                        {
                            if(flag4 == 1)
                            {
                                
                                parentsimicolon* t = new parentsimicolon(basecmd_1.at(0), basecmd_1.at(1));
                                parentAndAnd* t1 = new parentAndAnd(alldone, t);
                                alldone = t1;
                                
                                //alldone->execute();
                            }
                            else if(flag5 == 1)
                            {
                                parentsimicolon* t = new parentsimicolon(basecmd_1.at(0), basecmd_1.at(1));
                                parentBarBar* t1 = new parentBarBar(alldone, t);
                                alldone = t1;
                                //alldone->execute();
                            }
                            else if(flag6 == 1)
                            {
                                parentsimicolon* t = new parentsimicolon(basecmd_1.at(0), basecmd_1.at(1));
                                parentsimicolon* t1 = new parentsimicolon(alldone, t);
                                alldone = t1;
                            }
                            else
                            {
                                parentsimicolon* t = new parentsimicolon(basecmd_1.at(0), basecmd_1.at(1));
                                alldone = t;
                                basecmd_1.clear();
                                temp_1.clear();
                                --flag1;

                            }
                        }
                    }
                    else if(flag2 != 0)
                    {
                        if(flag2 == 1)
                        {
                            if(flag4 == 1)
                            {
                                //alldone->execute();
                                //basecmd_1.at(0)->execute();
                                //basecmd_1.at(1)->execute();
                                parentAndAnd* t = new parentAndAnd(basecmd_1.at(0), basecmd_1.at(1));
                                parentAndAnd* t1 = new parentAndAnd(alldone, t);
                                alldone = t1;
                                //alldone->execute();
                            }
                            else if(flag5 == 1)
                            {
                                parentAndAnd* t = new parentAndAnd(basecmd_1.at(0), basecmd_1.at(1));
                                parentBarBar* t1 = new parentBarBar(alldone, t);
                                alldone = t1;
                                //alldone->execute();
                            }
                            else if(flag6 == 1)
                            {
                                parentAndAnd* t = new parentAndAnd(basecmd_1.at(0), basecmd_1.at(1));
                                parentsimicolon* t1 = new parentsimicolon(alldone, t);
                                alldone = t1;
                            }
                            else
                            {
                                //cout << "3" << endl;
                                parentAndAnd* t = new parentAndAnd(basecmd_1.at(0), basecmd_1.at(1));
                                alldone = t; 
                                //t->execute();
                                basecmd_1.clear();
                                //basecmd_1.push_back(t);
                                temp_1.clear();
                                --flag2;
                            }
                        }
                        
                    }
                    else if(flag3 != 0)
                    {
                        if(flag3 == 1)
                        {
                            if(flag4 == 1)
                            {
                                parentBarBar* t = new parentBarBar(basecmd_1.at(0), basecmd_1.at(1));
                                parentAndAnd* t1 = new parentAndAnd(alldone, t);
                                alldone = t1;
                                //alldone->execute();
                            }
                            else if(flag5 == 1)
                            {
                                parentBarBar* t = new parentBarBar(basecmd_1.at(0), basecmd_1.at(1));
                                parentBarBar* t1 = new parentBarBar(alldone, t);
                                alldone = t1;
                                //alldone->execute();
                            }
                            else if(flag6 == 1)
                            {
                                parentBarBar* t = new parentBarBar(basecmd_1.at(0), basecmd_1.at(1));
                                parentsimicolon* t1 = new parentsimicolon(alldone, t);
                                alldone = t1;
                            }
                            else
                            {
                                parentBarBar* t = new parentBarBar(basecmd_1.at(0), basecmd_1.at(1));
                                alldone = t;
                                basecmd_1.clear();
                                temp_1.clear();
                                --flag3;
                            }
                        }
                    }
                    else
                    {
                        Cmd * c = new Cmd(temp_1);
                        if(flag4 == 1)
                        {
                            parentAndAnd* t1 = new parentAndAnd(alldone, c);
                            alldone = t1;
                            //alldone->execute();
                        }
                        if(flag5 == 1)
                        {
                            parentBarBar* t1 = new parentBarBar(alldone, c);
                            alldone = t1;
                        }
                        if(flag6 == 1)
                        {
                            parentsimicolon* t1 = new parentsimicolon(alldone, c);
                            alldone = t1;
                        }
                        //c->execute();
                        //temp_1.clear();
                    }
                }
                //if(i == cmds.size() - 2)
                //{
                    
                    //cout << "last" << endl;           
                    
                //}
            }
            if(strcmp(cmds.at(cmds.size() - 2),(char*)rightParentheses_1.c_str()) != 0)
            {
                Cmd * c = new Cmd(temp_1);
                if(flag4 == 1)
                {
                    parentAndAnd* t1 = new parentAndAnd(alldone, c);
                    alldone = t1;
                    //alldone->execute();
                }
                if(flag5 == 1)
                {
                    parentBarBar* t1 = new parentBarBar(alldone, c);
                    alldone = t1;
                }
                if(flag6 == 1)
                {
                    parentsimicolon* t1 = new parentsimicolon(alldone, c);
                    alldone = t1;
                }
            }
            
            alldone->execute(); // when it is all done 
        }
        
    }
    

    
    return 0;
}