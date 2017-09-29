#pragma once
class MyString
{
public:
	MyString(); //无参数构造函数
	MyString(const char* s);  //有参数构造函数
	MyString(const MyString&); //复制构造函数
	~MyString();//析构函数
	MyString& operator = (const MyString&);
	void Print();
private:
	char * data;
};

