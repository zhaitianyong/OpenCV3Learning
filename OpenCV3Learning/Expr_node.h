#pragma once
#include <iostream>
#include <string>
using namespace std;
class Expr_node
{
	friend ostream& operator << (ostream&,const Expr_node&);
	friend class Expr;
	int use;
public:
	virtual ~Expr_node();
	Expr_node() :use(1) {}
	virtual  void print(ostream&) const=0;
	virtual int eval() const = 0;
};


class Int_node :public Expr_node
{
	friend class Expr;
	int n;
public:
	Int_node(int k) :n(k) {};
	void print(ostream& o) const
	{
		o << n;
	}
	int eval() const
	{
		return n;
	}
	

};


class Unarry_node :public Expr_node
{
	friend class Expr;
	string op;// ²Ù×÷·ûºÅ
	Expr_node * opnd;
public:
	Unarry_node(const string& a, Expr_node* b) :op(a), opnd(b) {}
	void print(ostream& o) const
	{
		o << "(" << op << *opnd << ")";
	}
	int eval() const
	{
		if (op == "-") return -opnd->eval();
		throw "error";
	}
};


class Binary_node :public Expr_node
{
	friend class Expr;
	string op;
	Expr_node* left;
	Expr_node* right;
public:
	Binary_node(const string& _op, Expr_node* _left, Expr_node* _right) :op(_op), left(_left), right(_right) {}
	void print(ostream& o) const
	{
		o << "(" << *left << op << *right << ")";
	}
	int eval() const
	{
		if (op=="+")
		{
			return left->eval() + right->eval();
		}
		else if (op == "-")
		{
			return left->eval() - right->eval();
		}
		else if (op == "*")
		{
			return left->eval() * right->eval();
		}
		else if (op == "/")
		{
			if (right->eval()!=0)
			{
				return left->eval() / right->eval();
			}
			throw "error";
		}
		
	}
};
