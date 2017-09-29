#pragma once
#include <iostream>
using namespace std;
class Picture
{
	friend ostream& operator << (ostream&,const Picture&);
	friend Picture frame(const Picture&);
	friend Picture operator&(const Picture&, const Picture&);
	friend Picture operator|(const Picture&, const Picture&);
public:
	Picture();
	Picture(const char* const*,int);
	Picture(const Picture&);
	~Picture();
	Picture& operator=(const Picture&);
	static int max1(int,int);
private:
	int height, width;
	char * data;
	char& position(int row, int col) {
		return data[row*width+col];
	}
	char position(int row, int col) const{
		return data[row*width + col];
	}
	void init(int h,int w);
	void copyblock(int, int, const Picture&);
	void clear(int,int ,int ,int );
};


//Picture operator&(const Picture&, const Picture&);
//Picture operator|(const Picture&, const Picture&);

