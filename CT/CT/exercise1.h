#pragma once
#include "dollGame.h"

/*
인형을 뽑기 위한 문제의 보드와 이동방식만 지정해줌
*/

// dollGame 알고리즘을 상속 받음
class exercise1 : public dollGame	
{
public:	
	exercise1();

	// 문제마다 다른 보드를 만들어주고 다르게 이동시키기 위함
	void createBoard();
	void dollMove();
};

