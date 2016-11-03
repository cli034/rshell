#include "connector_composites.h"
using namespace std;

//how the function and constunctor are defined 
AndAnd::AndAnd(Basecmd* l, Basecmd* r)
{
	leftchild = l;
	rightchild = r;
}

int AndAnd::execute()
{
    if(leftchild->execute() != -1)
    {
        rightchild->execute();
    }
    
	return 1;
}

BarBar::BarBar(Basecmd* l, Basecmd* r)
{
	leftchild = l;
	rightchild = r;
}

int BarBar::execute()
{
    if(leftchild->execute() == -1)
    {
        rightchild->execute();
    }
    return 1;
}