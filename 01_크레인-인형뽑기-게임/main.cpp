#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int picked(int index, vector<vector<int>>& board)
{    
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][index - 1] != 0)//행[열index] 로 비어있지 않으면
        {
            int ret; //return 값 임시 저장
            ret = board[i][index - 1];
            board[i][index - 1] = 0;//꺼내졌으므로 해당자리는 0
            return ret;//리턴!
        }
    }

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //vector<int> basket;
    stack<int> basket;

    //바구니에 담기
    for (auto index : moves)
    {
        int doll = picked(index, board);

        if (doll == 0) continue;
        
        if(basket.empty()) basket.push(doll);
        else
        {
            if (basket.top() == doll)
            {
                basket.pop();
                answer += 2;
            }
            else
                basket.push(doll);
        }
   
    }


    
    return answer;
}//[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
//0 비어있음
//1 네오 : 2 무지 : 3 튜브 : 4 어피치 : 5 프로도
//4311324
int main()
{
    cout<<solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 })<<endl;
}