#include "stdafx.h"
#include "Expr_node.h"




Expr_node::~Expr_node()
{
	std::cout << "~Expr_node" << std::endl;
}

ostream & operator<<(ostream & o, const Expr_node & e)
{
	// TODO: �ڴ˴����� return ���
	e.print(o);
	return o;
}
