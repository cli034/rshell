#include "connector_composites.h"
#include <iostream>
using namespace std;

//how the function and constunctor are defined 
AndAnd::AndAnd(Basecmd* l, Basecmd* r)
{
	leftchild = l;
	rightchild = r;
}

int AndAnd::execute()
{
    if(leftchild->execute() == 0)
    {
        return rightchild->execute();
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
    if(leftchild->execute() != 0)
    {
        return rightchild->execute();
    }
    return 0; 
}

parentAndAnd::parentAndAnd(Basecmd* l, Basecmd* r)
{
    leftchild = l;
    rightchild = r;
}

int parentAndAnd::execute()
{
    if(leftchild->execute() == 0)
    {
        if(rightchild->execute() == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

parentBarBar::parentBarBar(Basecmd* l, Basecmd* r)
{
    leftchild = l;
    rightchild = r;
}

int parentBarBar::execute()
{
    if(leftchild->execute() != 0)
    {
        if(rightchild->execute() != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

parentsimicolon::parentsimicolon(Basecmd* l, Basecmd* r)
{
    leftchild = l;
    rightchild = r;
}

int parentsimicolon::execute()
{
    if(leftchild->execute() == 0)
    {
        if(rightchild->execute() == 0)
        {
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else if(leftchild->execute() != 0)
    {
        if(rightchild->execute() != 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    return 0;
}