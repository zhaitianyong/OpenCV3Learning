#include "stdafx.h"
#include "Picture.h"
#include <stdlib.h>

int Picture::max1(int m, int n)
{
	return m>n ? m : n;
}


Picture::Picture():height(0),width(0),data(0)
{
}

Picture::Picture(const char * const * array, int n)
{
	int w = 0;
	for (size_t i = 0; i < n; i++)
	{
		w = Picture::max1(w,strlen(array[i]));
	}
	init(n,w);

	for (size_t i = 0; i < n; i++)
	{
		const char* src = array[i];
		int len = strlen(src);
		int j = 0;
		while (j < len)
		{
			position(i, j) = src[j];
			++j;
		}
		while (j < width)
		{
			position(i, j) = ' ';
			++j;
		}
	}
}

Picture::Picture(const Picture & p)
{
	init(p.height,p.width);
	copyblock(0, 0, p);
}


void Picture::init(int h, int w)
{
	height = h;
	width = w;
	data = new char[height* width];
}
void Picture::copyblock(int row, int col, const Picture& p)
{
	for (size_t i = 0; i < p.height; i++)
	{
		for (size_t j = 0; j < p.width ; j++)
		{
			position(i + row, j + col) = p.position(i,j);
		}
	}
}

void Picture::clear(int r1, int c1, int r2, int c2)
{
	for (size_t r = r1; r < r2; r++)
	{
		for (size_t c = c1; c < c2; c++)
		{
			position(r, c) = ' ';
		}
	}
}

Picture & Picture::operator=(const Picture & p)
{
	// TODO: 在此处插入 return 语句
	if (this!=&p)
	{
		delete[] data;
		init(p.height,p.width);
		copyblock(0, 0, p);
	}
	return *this;
}

ostream & operator<<(ostream & out, const Picture & p)
{
	// TODO: 在此处插入 return 语句
	//out << p
	for (size_t i = 0; i < p.height ; i++)
	{
		for (size_t j = 0; j < p.width ; j++)
		{
			out << p.position(i,j);
		}
		out << endl;
	}
	return out;
}


Picture::~Picture()
{
	delete[] data;
}







Picture frame(const Picture& p)
{
	Picture r;
	r.init(p.height + 2, p.width + 2);
	for (size_t i = 0; i < r.height-1; i++)
	{
		r.position(i, 0) = '|';
		r.position(i, r.width - 1) = '|';
	}

	for (size_t j = 1; j < r.width-1; j++)
	{
		r.position(0, j) = '-';
		r.position(r.height - 1,j) = '-';
	}
	r.position(0, 0) = '+';
	r.position(0, r.width - 1) = '+';
	r.position(r.height - 1, 0) = '+';
	r.position(r.height - 1, r.width - 1) = '+';
	r.copyblock(1,1,p);
	return r;
}

Picture operator&(const Picture & p1, const Picture & p2)
{
	Picture r;

	r.init(p1.height+p2.height,Picture::max1(p1.width,p2.width));
	r.clear(0,p1.width,p1.height,r.width);
	r.clear(p1.height,p2.width,r.height,r.width);
	r.copyblock(0,0,p1);
	r.copyblock(p1.height, 0, p2);

	return r;
}

Picture operator|(const Picture & p1, const Picture & p2)
{
	Picture r;

	r.init(Picture::max1(p1.height, p2.height),p1.width+p2.width);
	r.clear(p1.height, 0, r.height, p1.width);
	r.clear(p2.height, p1.width, r.height, r.width);
	r.copyblock(0, 0, p1);
	r.copyblock(0, p1.width, p2);

	return r;
}
