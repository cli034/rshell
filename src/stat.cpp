#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    struct stat buf;
    string s = "/home/ubuntu/workspace/src/t.cpp";
    string s1 = "t1";
    vector<char*> a;
    a.push_back((char*)s1.c_str());
    a.push_back((char*)s.c_str());
    
    stat(a[0], &buf);
    cout << buf.st_mode << endl; 
    if(S_ISREG(buf.st_mode))
    {
        cout << "this is regular file" << endl;
    }
    else if(S_ISDIR(buf.st_mode))
    {
        cout << "this is a directory" << endl;
    }
    
    
    return 0;
}