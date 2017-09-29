#pragma once
#include "Expr_node.h"
class Expr
{
	friend ostream& operator << (ostream&, const Expr&);
	Expr_node* p;
public:
	Expr(int);
	Expr(const string&, Expr);
	Expr(const string&, Expr, Expr);
	Expr(const Expr&);
	Expr& operator=(const Expr&);
    ~Expr();
	int eval() const { return p->eval(); } 
};

