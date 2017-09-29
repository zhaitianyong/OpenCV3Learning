#include "stdafx.h"
#include "Timer.h"

using namespace std;

void CTimer::start()
{
	m_start = clock();
}
void CTimer::stop()
{
	m_end = clock();
}
void CTimer::reset()
{
	m_start = 0;
	m_end = 0;
}
void CTimer::print() const
{
	cout << m_end - m_start << " ms" << endl;
	//cout << float(m_end-m_start)/CLK_TCK << endl;
}
//void CTimer::print(ostream& out)
//{
//	out << m_end - m_start << " ms" << endl;
//}

//ostream & operator<<(ostream & out, const CTimer & t)
//{
//	// TODO: �ڴ˴����� return ���
//	t.print();
//	return out;
//}
