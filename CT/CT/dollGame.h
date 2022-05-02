#pragma once
#include <vector>
#include <string>
using namespace std;

/*
���� �̱� ���� �˰��� �ֻ��� �θ�

��� ���� : board, moves
��� �Լ� : solution(~), printResult()
*/

class dollGame
{
public:
	dollGame();
	
	vector<vector<int>> board; // ���� �̱� ���� board
	vector<int> moves; // ������ �̴� �̵� ����

	// �����̴� �˰��� � ������ �׻� ���ƾ���
	int solution(vector<vector<int>> board, vector<int> moves);

	// �ش� ������ ����� �����
	void printResult();
};

