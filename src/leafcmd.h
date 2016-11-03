#ifndef __LEAFCMD_H_
#define __LEAFCMD_H_

#include "basecmd.h"
#include <vector>
using namespace std;
//leaf cmd class
class Cmd : public Basecmd
{
	private:
	vector<char*> cmds_to_execute;
	
	public:
	Cmd(vector<char*> a);
	int execute();
};

#endif