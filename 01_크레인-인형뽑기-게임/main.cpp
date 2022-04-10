#include <iostream>
#include <string>
#include <vector>

using namespace std;

int picked(int index, vector<vector<int>>& board)
{
    int cnt = 1;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][index-1] != 0)//행[열index] 로 비어있지 않으면
        {
            int ret; //return 값 임시 저장
            ret = board[i][index - 1];
            board[i][index - 1] = 0;//꺼내졌으므로 해당자리는 0
            return ret;//리턴!
        }
    }

    //for (auto &row : myboard) //행 순회
    //{
    //    for (auto &column : row)
    //    {
    //        if (column != 0 && index == cnt)//행[열index] 로 비어있지 않으면
    //        {
    //            int ret; //return 값 임시 저장
    //            ret = column;
    //            column = 0;//꺼내졌으므로 해당자리는 0
    //            return ret;//리턴!
    //        }
    //        cnt++;
    //    }
    //    cnt = 1;
    //}

}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;

    //바구니에 담기
    for (auto index : moves)
    {
        basket.push_back(picked(index, board));
    }

    //같은 인형 연속으로(2개이상)있으면 삭제하기.
    for (int i = 1; i < basket.size(); i++)
    {
        int prev = basket[i - 1]; //이전인형
        if (basket[i] == prev)
        {
            answer += 2;
            i++; //prev가 비었기 떄문에 인덱스 값을 하나 더 늘려준다.
        }

    }
    return answer;
}//[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
//0 비어있음
//1 네오 : 2 무지 : 3 튜브 : 4 어피치 : 5 프로도
int main()
{
    cout<<solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 })<<endl;
}