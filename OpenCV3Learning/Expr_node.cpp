#include "stdafx.h"
#include "Expr_node.h"




Expr_node::~Expr_node()
{
	std::cout << "~Expr_node" << std::endl;
}

ostream & operator<<(ostream & o, const Expr_node & e)
{
	// TODO: 在此处插入 return 语句
	e.print(o);
	return o;
}
