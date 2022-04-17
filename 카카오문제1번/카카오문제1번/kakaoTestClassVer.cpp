#include <string>
#include <vector>
#include <stack>

using namespace std;

class SolutionClass {
public:
	int answer = 0;
	vector<vector<int>> board;
	vector<int> moves;
	int solution(vector<vector<int>> board, vector<int> moves); // 함수 인자도 클래스에서 선언한 10~11째줄로 넣고 싶은데 그걸 어떻게 하는지 모르겠고
	// 이럴 거면 class를 쓰는 게 더 낭비라는 생각이 드는 걸 보면 상당히 잘못된 코드인 것으로 판정된다..
};

int SolutionClass::solution(vector<vector<int>> board, vector<int> moves) {

	SolutionClass sol;
	sol.answer = 0;

	stack<int> stack; // 이 스택은 바구니를 의미

	// 일단 먼저 moves(행)을 순회한다 (생각해 보니 열의 맨 위를 잡아야 하는 거니까 top 꺼내서 쓰면 되지 않을까? => 스택)
	for (int i = 0; i < moves.size(); i++) {
		int picked = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			// 비어있지 않다면
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