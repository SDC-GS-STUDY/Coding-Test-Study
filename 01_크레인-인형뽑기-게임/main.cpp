#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int picked(int index, vector<vector<int>>& board)
{    
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][index - 1] != 0)//��[��index] �� ������� ������
        {
            int ret; //return �� �ӽ� ����
            ret = board[i][index - 1];
            board[i][index - 1] = 0;//���������Ƿ� �ش��ڸ��� 0
            return ret;//����!
        }
    }

    return 0;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    //vector<int> basket;
    stack<int> basket;

    //�ٱ��Ͽ� ���
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
//0 �������
//1 �׿� : 2 ���� : 3 Ʃ�� : 4 ����ġ : 5 ���ε�
//4311324
int main()
{
    cout<<solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 })<<endl;
}