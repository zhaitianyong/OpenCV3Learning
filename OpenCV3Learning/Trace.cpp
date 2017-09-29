/************************************************************************
> File Name: 
> Author:atway
> Mail:atway#126.com(#=>@)
> Created Time: 2014��10��15�� ������ 12ʱ00��33��
************************************************************************/
#include "stdafx.h"
#include "Trace.h"

Trace::Trace() 
{
	noisy = 0;
}
Trace::Trace(FILE* f)
{
	this->f = f;
}
Trace::~Trace() {
}

void Trace::Print(char* s) {
	//if (noisy) printf("%s\n", s);
	if (noisy) fprintf(f, "%s\n", s);
}

void Trace::on() {
	noisy = 1;
}
void Trace::off() {
	noisy = 0;
}

