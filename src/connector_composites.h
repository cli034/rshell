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
	//virtual ~AndAnd() {};
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

class parentAndAnd : public Basecmd
{
	private:
	Basecmd* leftchild;
	Basecmd* rightchild;
	
	public:
	parentAndAnd(Basecmd* l, Basecmd* r);
	int execute();
};

class parentBarBar : public Basecmd
{
	private:
	Basecmd* leftchild;
	Basecmd* rightchild;
	
	public:
	parentBarBar(Basecmd* l, Basecmd* r);
	int execute();
};

class parentsimicolon : public Basecmd
{
	private:
	Basecmd* leftchild;
	Basecmd* rightchild;
	
	public:
	parentsimicolon(Basecmd* l, Basecmd* r);
	int execute();
};


#endif
