#ifndef __BASECMD_H_
#define __BASECMD_H_
//the base class
class Basecmd
{
	public:
	 Basecmd() {};
	 virtual int execute() = 0;
};

#endif