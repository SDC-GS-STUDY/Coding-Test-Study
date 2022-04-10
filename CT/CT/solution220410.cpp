#include <iostream>
#include <string>
#include <vector>
#include <stack>

/*
 <����>
 �ٱ��� ���� �Ʒ� ĭ ���� ������ ������� ���� --> ���� �ٱ���
 �ٱ��Ͽ� �����ؼ� ���̸� �Ͷ߷����鼭 �����.
 ������ ���� ������ �۵��ϴ� ��� �ƹ��� �ϵ� �Ͼ�� ����
 board size 5*5 ~ 30*30, value(������ ����) 1~100
 move size 1~1000
*/

using namespace std;

/*
 <���̵��>
 ���� ã��--> moves�� value�� col�̰� 0�� �ƴ� ���� ã���� ���ÿ� push�ϱ�
  ����, row�� ���Ҵµ� ��� 0�̸� �׳� �Ѿ��

 ���ÿ��� ���� ���� �����Ͽ� ������ ���� �� �� pop�ϰ� 2���� answer�� �����ֱ� 
*/

int solution(vector<vector<int>> board, vector<int> moves)
{
	int answer = 0;

	stack<int> s;

	for (int j = 0; j < moves.size(); j++)
	{
		// ũ������ ������ ���ߵǴϱ� moves�� �̵��� ���κ��� �����ϰ� �޿� ���Բ�
		for (int i = 0; i < board.size(); i++) // ��ü �� ����
		{		
			if (board[i][moves[j]-1] != 0) // ������ ���� i ���� moves[i]-1�� ������ �ִٸ�
			{
				if (board[i][moves[j]-1] == s.top()) // �������� ������
				{
					s.pop(); // �ϳ� ����
					answer += 2; // �ΰ��� �����ֱ�
				}
				else
					s.push(board[i][moves[j]-1]); // ���ؿ� Ǫ��		

				board[i][moves[j-1]] = 0; // ���� ���� ó��
				break; // �ϳ� �����ϸ� �� �ؿ� �ִ� ���� �糢�� ���� �̵�����
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