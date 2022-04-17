#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include "dollGame.h"

using namespace std;

/*
인형뽑기 알고리즘, 출력
*/

dollGame::dollGame()
	:board(0), moves(0)
{
}

int dollGame::solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;
	s.push(0); // 스택이 비면 바로 오류나길래 기본값넣어둠 어차피 0은 인형이 아니니까

	for (int j = 0; j < moves.size(); j++)
	{
		// 크레인이 안으로 들어가야되니까 moves로 이동할 열부분을 고정하고 쭈욱 들어가게끔
		for (int i = 0; i < board.size(); i++) // 전체 다 돌아
		{
			if (board[i][moves[j] - 1] != 0) // 보드의 행은 i 열은 moves[i]-1에 인형이 있다면
			{
				if (board[i][moves[j] - 1] == s.top()) // 연속으로 같으면
				{
					if (s.empty()) break; // 예외 처리

					s.pop(); // 하나 빼고
					answer += 2; // 두개씩 더해주기

				}
				else
					s.push(board[i][moves[j] - 1]); // 스텍에 푸시		

				board[i][moves[j] - 1] = 0; // 인형 삭제 처리
				break; // 하나 삭제하면 그 밑에 있는 놈은 재끼고 다음 이동으로
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
