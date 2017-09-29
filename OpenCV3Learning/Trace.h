#pragma once


class Trace 
{
public:
	Trace();
	Trace(FILE * f);
	~Trace();
	void Print(char* s);
	void on();
	void off();
private:
	int noisy;
	FILE* f;
};