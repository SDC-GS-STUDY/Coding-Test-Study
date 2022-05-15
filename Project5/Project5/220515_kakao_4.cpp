#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;


    //일단 
    //[][]
    //[][]
    //이렇게 있다고 하면 좌표값ㅇ으로 생각해야되나?
    //[x,y+1][x+1,y+1]
    //[x,y][x+1,y]
    //그럼 x,y랑 각각이 같을때랑 다를때 나눠서 확인하고

    //x,y값 만들기
    int x, int y;

    for(int i = 0; i<n; i++) 
	{
        for(int j = 0; j <m; j++)
        {
            int value = board[i][j];

            if(board[i][j] == board[i+1][j])

    return answer;
}