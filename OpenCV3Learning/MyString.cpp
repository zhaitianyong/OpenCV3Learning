#include "stdafx.h"
#include "MyString.h"
#include <string.h>

MyString::MyString()
{
}

MyString::MyString(const char* s)
{
	delete[] data;
	data = new char[strlen(s)];
	strcpy(data, s);
}
MyString::MyString(const MyString& s)
{
	delete[] data;
	data = new char[strlen(s.data)];
	strcpy(data, s.data);
}
void MyString::Print() {
	printf("%x\n", &data);
	printf("%s\n",data);
}

MyString& MyString::operator = (const MyString& s)
{
	if (&s!=this)
	{
		delete[] data;
		data = new char[strlen(s.data)];
		strcpy(data, s.data);
	}
	return *this;
	
}
MyString::~MyString()
{
	if (!data)
	{
		printf("~MyString");
		delete[] data;
	}
	
}
