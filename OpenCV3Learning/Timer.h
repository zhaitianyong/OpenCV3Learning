#pragma once
#include <iostream>
#include <ctime>

class CTimer
{
	//friend ostream& operator << (ostream&, const CTimer&);
public:
	void reset();
	void start();
	void stop();
	void print() const;
private:
	clock_t m_start;
	clock_t m_end;
};

