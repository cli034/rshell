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
        
        string first_connetor = ";";
        
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
            unsigned i = 0;
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

    
    return 0;
}