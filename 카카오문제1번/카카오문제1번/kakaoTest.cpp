#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0; // 터진 개수
	stack<int> stack; // 이 스택은 바구니를 의미

	// 일단 먼저 moves(행)을 순회한다 (생각해 보니 열의 맨 위를 잡아야 하는 거니까 top 꺼내서 쓰면 되지 않을까? => 스택)
	for (int i = 0; i < moves.size(); i++) {
		int picked = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			// 비어있지 않다면
			if (board[j][picked] != 0) {
				if (!stack.empty() && stack.top() == board[j][picked]) {
					answer += 2;
					stack.pop();
				}
				else
					stack.push(board[j][picked]);
				board[j][picked] = 0;
				break;
			}
		}
	}

	return answer;

}

int main() {
	printf("%d", solution({{0, 0, 0, 0, 0}, {0, 0, 1, 0, 3}, {0, 2, 5, 0, 1}, {4, 2, 4, 4, 2}, {3, 5, 1, 3, 1}}, {1, 5, 3, 5, 1, 2, 1, 4}));
}