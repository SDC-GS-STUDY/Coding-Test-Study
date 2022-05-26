#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;

    // �� ���� �������� �������� ������ ������ �ҹ��ڷ� �ٲٴ� ����
    // ó���� �߸� �����ߴ� �� : �� ���� '����'���� ��ƾ� �ϴµ�, �׳� ������ ���� ���������� ���ٰ� �ؼ� ���� ����
    while (true) {
        flag = false;
        for (int i = 1; i < board.size(); i++) {
            for (int j = 0; j < board[i].size() - 1; j++) {
                if (board[i][j] != ' ' && (tolower(board[i][j]) == tolower(board[i - 1][j])) &&
                    (tolower(board[i][j]) == tolower(board[i][j + 1])) &&
                    (tolower(board[i][j]) == tolower(board[i - 1][j + 1]))) {

                    board[i][j] = tolower(board[i][j]);
                    board[i - 1][j] = board[i][j];
                    board[i][j + 1] = board[i][j];
                    board[i - 1][j + 1] = board[i][j];
                    flag = true;

                }
            }
        }
        if (flag == false)
            break;

        // �ҹ��ڷ� �ٲ� �ֵ��� �� ���ְ� -> �� ������ answer++ �ϴ� ����
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    board[i][j] = ' ';
                    answer++;
                }
            }
        }

        // �� ���� �����ϴµ�, ������ + �ڿ������� ���ʴ�� ���� ����
        for (int i = board.size() - 1; i >= 0; i--) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == ' ') {
                    for (int x = i - 1; x >= 0; x--) {
                        if (board[x][j] != ' ') {
                            board[i][j] = board[x][j];
                            board[x][j] = ' ';
                            break;
                        }
                    }
                }
            }
        }
    }

    



    return answer;
}