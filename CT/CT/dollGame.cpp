#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "dollGame.h"

using namespace std;

/*
�����̱� �˰���, ���
*/

dollGame::dollGame()
	:board(0), moves(0)
{
}

int dollGame::solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;
	s.push(0); // ������ ��� �ٷ� �������淡 �⺻���־�� ������ 0�� ������ �ƴϴϱ�

	for (int j = 0; j < moves.size(); j++)
	{
		// ũ������ ������ ���ߵǴϱ� moves�� �̵��� ���κ��� �����ϰ� �޿� ���Բ�
		for (int i = 0; i < board.size(); i++) // ��ü �� ����
		{
			if (board[i][moves[j] - 1] != 0) // ������ ���� i ���� moves[i]-1�� ������ �ִٸ�
			{
				if (board[i][moves[j] - 1] == s.top()) // �������� ������
				{
					if (s.empty()) break; // ���� ó��

					s.pop(); // �ϳ� ����
					answer += 2; // �ΰ��� �����ֱ�

				}
				else
					s.push(board[i][moves[j] - 1]); // ���ؿ� Ǫ��		

				board[i][moves[j] - 1] = 0; // ���� ���� ó��
				break; // �ϳ� �����ϸ� �� �ؿ� �ִ� ���� �糢�� ���� �̵�����
			}
		}
	}

	return answer;
}


void dollGame::printResult()
{
	int result = solution(board, moves);

	cout << result << endl;
}
