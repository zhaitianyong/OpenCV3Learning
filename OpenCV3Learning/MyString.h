#pragma once
class MyString
{
public:
	MyString(); //�޲������캯��
	MyString(const char* s);  //�в������캯��
	MyString(const MyString&); //���ƹ��캯��
	~MyString();//��������
	MyString& operator = (const MyString&);
	void Print();
private:
	char * data;
};

