#pragma once
#include <vector>
#include <string>
using namespace std;

/*
인형 뽑기 게임 알고리즘 최상위 부모

멤버 변수 : board, moves
멤버 함수 : solution(~), printResult()
*/

class dollGame
{
public:
	dollGame();
	
	vector<vector<int>> board; // 인형 뽑기 게임 board
	vector<int> moves; // 인형을 뽑는 이동 순서

	// 인형뽑는 알고리즘 어떤 문제라도 항상 같아야함
	int solution(vector<vector<int>> board, vector<int> moves);

	// 해당 문제의 결과를 출력함
	void printResult();
};

