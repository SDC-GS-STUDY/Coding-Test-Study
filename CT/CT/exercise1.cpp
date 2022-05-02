#include "exercise1.h"

/*
¹®Á¦1
*/

exercise1::exercise1()
{	
}

void exercise1::createBoard()
{
	board = {
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1}
	};
}

void exercise1::dollMove()
{
	moves = { 1,5,3,5,1,2,1,4 };
}

