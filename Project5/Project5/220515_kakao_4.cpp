#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;


    //�ϴ� 
    //[][]
    //[][]
    //�̷��� �ִٰ� �ϸ� ��ǥ�������� �����ؾߵǳ�?
    //[x,y+1][x+1,y+1]
    //[x,y][x+1,y]
    //�׷� x,y�� ������ �������� �ٸ��� ������ Ȯ���ϰ�

    //x,y�� �����
    int x, int y;

    for(int i = 0; i<n; i++) 
	{
        for(int j = 0; j <m; j++)
        {
            int value = board[i][j];

            if(board[i][j] == board[i+1][j])

    return answer;
}