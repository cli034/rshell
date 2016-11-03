#ifndef __CONNECTORCOMPOSITENODES_H_
#define __CONNECTORCOMPOSITENODES_H_

#include "basecmd.h"
//the connectorcompistie class of && and ||
class AndAnd : public Basecmd
{
	private:
	Basecmd* leftchild;
	Basecmd* rightchild;
	
	public:
	AndAnd(Basecmd* l, Basecmd* r);
	int execute();
};

class BarBar : public Basecmd
{                      	
	private:
	Basecmd* leftchild;
	Basecmd* rightchild;
	
	public:
	BarBar(Basecmd* l, Basecmd* r); 
	int execute();
};


#endif
