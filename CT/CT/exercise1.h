#pragma once
#include "dollGame.h"

/*
������ �̱� ���� ������ ����� �̵���ĸ� ��������
*/

// dollGame �˰����� ��� ����
class exercise1 : public dollGame	
{
public:	
	exercise1();

	// �������� �ٸ� ���带 ������ְ� �ٸ��� �̵���Ű�� ����
	void createBoard();
	void dollMove();
};

