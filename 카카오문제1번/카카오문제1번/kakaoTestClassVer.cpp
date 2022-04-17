#include <string>
#include <vector>
#include <stack>

using namespace std;

class SolutionClass {
public:
	int answer = 0;
	vector<vector<int>> board;
	vector<int> moves;
	int solution(vector<vector<int>> board, vector<int> moves); // �Լ� ���ڵ� Ŭ�������� ������ 10~11°�ٷ� �ְ� ������ �װ� ��� �ϴ��� �𸣰ڰ�
	// �̷� �Ÿ� class�� ���� �� �� ������ ������ ��� �� ���� ����� �߸��� �ڵ��� ������ �����ȴ�..
};

int SolutionClass::solution(vector<vector<int>> board, vector<int> moves) {

	SolutionClass sol;
	sol.answer = 0;

	stack<int> stack; // �� ������ �ٱ��ϸ� �ǹ�

	// �ϴ� ���� moves(��)�� ��ȸ�Ѵ� (������ ���� ���� �� ���� ��ƾ� �ϴ� �Ŵϱ� top ������ ���� ���� ������? => ����)
	for (int i = 0; i < moves.size(); i++) {
		int picked = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			// ������� �ʴٸ�
			if (board[j][picked] != 0) {
				if (!stack.empty() && stack.top() == board[j][picked]) {
					sol.answer += 2;
					stack.pop();
				}
				else
					stack.push(board[j][picked]);
				board[j][picked] = 0;
				break;
			}
		}
	}

	return sol.answer;
}

int main() {
	SolutionClass sol;
	sol.board = { {0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1} };
	sol.moves = { 1, 5, 3, 5, 1, 2, 1, 4 };

	printf("%d", sol.solution(sol.board, sol.moves));
}