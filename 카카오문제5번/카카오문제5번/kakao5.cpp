#include <string>
#include <iostream>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = true;

    // 한 점을 기준으로 동서남북 돌려서 같으면 소문자로 바꾸는 과정
    // 처음에 잘못 생각했던 점 : 한 점을 '기준'으로 잡아야 하는데, 그냥 기준이 없고 동서남북이 같다고만 해서 오류 떴음
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

        // 소문자로 바뀐 애들을 다 없애고 -> 그 다음에 answer++ 하는 과정
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] >= 'a' && board[i][j] <= 'z') {
                    board[i][j] = ' ';
                    answer++;
                }
            }
        }

        // 빈 곳을 삭제하는데, 세로줄 + 뒤에서부터 차례대로 없앨 거임
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