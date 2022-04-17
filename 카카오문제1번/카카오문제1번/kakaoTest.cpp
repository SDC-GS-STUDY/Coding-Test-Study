#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0; // ���� ����
	stack<int> stack; // �� ������ �ٱ��ϸ� �ǹ�

	// �ϴ� ���� moves(��)�� ��ȸ�Ѵ� (������ ���� ���� �� ���� ��ƾ� �ϴ� �Ŵϱ� top ������ ���� ���� ������? => ����)
	for (int i = 0; i < moves.size(); i++) {
		int picked = moves[i] - 1;
		for (int j = 0; j < board.size(); j++) {
			// ������� �ʴٸ�
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