#include <iostream>
#include <string>
#include <vector>
#include <stack>

/*
 <문제>
 바구니 가장 아래 칸 부터 인형이 순서대로 쌓임 --> 스텍 바구니
 바구니에 연속해서 쌓이면 터뜨려지면서 사라짐.
 인형이 없는 곳에서 작동하는 경우 아무런 일도 일어나지 않음
 board size 5*5 ~ 30*30, value(인형의 종류) 1~100
 move size 1~1000
*/

using namespace std;

/*
 <아이디어>
 인형 찾기--> moves의 value가 col이고 0이 아닌 수를 찾으면 스택에 push하기
  만약, row다 돌았는데 모두 0이면 그냥 넘어가고

 스택에서 같은 수가 연속하여 들어오면 같은 수 다 pop하고 2개씩 answer에 더해주기 
*/

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;

	for (int j = 0; j < moves.size(); j++)
	{
		// 크레인이 안으로 들어가야되니까 moves로 이동할 열부분을 고정하고 쭈욱 들어가게끔
		for (int i = 0; i < board.size(); i++) // 전체 다 돌아
		{		
			if (board[i][moves[j]-1] != 0) // 보드의 행은 i 열은 moves[i]-1에 인형이 있다면
			{
				if (board[i][moves[j]-1] == s.top()) // 연속으로 같으면
				{
					s.pop(); // 하나 빼고
					answer += 2; // 두개씩 더해주기
				}
				else
					s.push(board[i][moves[j]-1]); // 스텍에 푸시		

				board[i][moves[j-1]] = 0; // 인형 삭제 처리
				break; // 하나 삭제하면 그 밑에 있는 놈은 재끼고 다음 이동으로
			}
		}
	}	

	return answer;
}

int main()
{
	vector<vector<int>> board = {
		{0,0,0,0,0},
		{0,0,1,0,3},
		{0,2,5,0,1},
		{4,2,4,4,2},
		{3,5,1,3,1}
	};
	vector<int> moves = { 1,5,3,5,1,2,1,4 };

	int result = solution(board, moves);

	cout << result << endl;

	return 0;
}