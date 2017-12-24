#include <iostream>
#include <stdlib.h>
using namespace std;
class checkerpiece
{
protected:
	int x;
	int y;
	bool king;
	bool selected;
public:
	int givexposition(void);
	int giveyposition(void);
	void select(void);
	void unselect(void);
	bool whetherselected(void);
	//bool alljump(void);  <- Implement This!
	checkerpiece(int startx, int starty, bool kingship = 0);
};

int checkerpiece::givexposition(void)
{
	return(x);
}

int checkerpiece::giveyposition(void)
{
	return(y);
}

void checkerpiece::select(void)
{
	selected = 1;
}

void checkerpiece::unselect(void)
{
	selected = 0;
}

bool checkerpiece::whetherselected(void)
{
	return(selected);
}

checkerpiece::checkerpiece(int startx, int starty, bool kingship)
{
	x = startx;
	y = starty;
	king = kingship;
}

//White Piece

class wpiece : public checkerpiece
{
public:
	bool moveup(int nextx, int nexty, int matrix[8][8]);
	bool jumpup(int nextx, int nexty, int matrix[8][8]);
	wpiece(int startx = -1, int starty = -1, bool kingship = 0);
};

bool wpiece::jumpup(int nextx, int nexty, int matrix[8][8])
{
	if (nextx == x + 2 && nexty == y + 2 && matrix[x + 1][y + 1] == 2)
	{
		matrix[x][y] = 0;
		matrix[x + 1][y + 1] = 0;
		matrix[x + 2][y + 2] = 1;

		x = x + 2;
		y = y + 2;
		cout << "jumped up right" << endl;
		return(1);
	}
	if (nextx == x - 2 && nexty == y + 2 && matrix[x - 1][y + 1] == 2)
	{
		matrix[x][y] = 0;
		matrix[x - 1][y + 1] = 0;
		matrix[x - 2][y + 2] = 1;

		x = x - 2;
		y = y + 2;
		cout << "jumped up left" << endl;
		return(1);
	}

	cout << "No Jump - sorry" << endl;

	return(0);
}

bool wpiece::moveup(int nextx, int nexty, int matrix[8][8])
{
	if (nextx == x + 1 && nexty == y + 1 && matrix[x][y] == 0)
	{
		cout << matrix[x - 1][y - 1] << endl;
		matrix[x - 1][y - 1] = 0;
		matrix[x][y] = 1;

		cout << matrix[x][y] << endl;

		x++;
		y++;

		cout << matrix[x - 1][y - 1] << endl;
		cout << "moved up right" << endl;

		return(1);
	}
	if (nextx == x - 1 && nexty == y + 1 && matrix[x - 2][y] == 0)
	{
		matrix[x - 1][y - 1] = 0;
		matrix[x - 2][y] = 1;

		x--;
		y++;
		cout << "moved up left" << endl;
		return(1);
	}

	cout << "no move - sorry" << endl;

	return(0);
}

wpiece::wpiece(int startx, int starty, bool kingship) :checkerpiece(startx, starty, king)
{
	x = startx;
	y = starty;
	king = kingship;
}

//CLASS-RELATED PROTOTYPES

void printpieces(wpiece whitepiece[12]);
int findpiece(wpiece whitepiece[12], int x, int y);
#pragma once
