#include "stdafx.h"
#include "Expr.h"



Expr::Expr(int n)
{
	p = new Int_node(n);
}

Expr::Expr(const string & op, Expr e)
{
	p = new Unarry_node(op, e.p);
}

Expr::Expr(const string & op, Expr left, Expr right)
{
	p = new Binary_node(op, left.p, right.p);
}

Expr::Expr(const Expr & e)
{
	p = e.p;
	++p->use;
}

Expr & Expr::operator=(const Expr & e)
{
	// TODO: 在此处插入 return 语句
	e.p->use++;
	if (--p->use==0)
	{
		delete p;
	}
	p = e.p;
	return *this;
}


Expr::~Expr()
{
	std::cout << "~Expr" << std::endl;
	//std::cout << p->use << std::endl;
	p->print(std::cout);
	/*if (--p->use==0)
	{
		delete p;
	}*/
	
}

ostream & operator<<(ostream & o, const Expr & e)
{
	// TODO: 在此处插入 return 语句
	e.p->print(o);
	return o;
}
