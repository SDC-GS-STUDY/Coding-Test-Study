#include <iostream>
#include <string>
#include <vector>

using namespace std;

int picked(int index, vector<vector<int>>& board)
{
    int cnt = 1;
    for (int i = 0; i < board.size(); i++)
    {
        if (board[i][index-1] != 0)//��[��index] �� ������� ������
        {
            int ret; //return �� �ӽ� ����
            ret = board[i][index - 1];
            board[i][index - 1] = 0;//���������Ƿ� �ش��ڸ��� 0
            return ret;//����!
        }
    }

    //for (auto &row : myboard) //�� ��ȸ
    //{
    //    for (auto &column : row)
    //    {
    //        if (column != 0 && index == cnt)//��[��index] �� ������� ������
    //        {
    //            int ret; //return �� �ӽ� ����
    //            ret = column;
    //            column = 0;//���������Ƿ� �ش��ڸ��� 0
    //            return ret;//����!
    //        }
    //        cnt++;
    //    }
    //    cnt = 1;
    //}

}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;

    //�ٱ��Ͽ� ���
    for (auto index : moves)
    {
        basket.push_back(picked(index, board));
    }

    //���� ���� ��������(2���̻�)������ �����ϱ�.
    for (int i = 1; i < basket.size(); i++)
    {
        int prev = basket[i - 1]; //��������
        if (basket[i] == prev)
        {
            answer += 2;
            i++; //prev�� ����� ������ �ε��� ���� �ϳ� �� �÷��ش�.
        }

    }
    return answer;
}//[[0,0,0,0,0],[0,0,1,0,3],[0,2,5,0,1],[4,2,4,4,2],[3,5,1,3,1]]
//0 �������
//1 �׿� : 2 ���� : 3 Ʃ�� : 4 ����ġ : 5 ���ε�
int main()
{
    cout<<solution({ {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} }, { 1, 5, 3, 5, 1, 2, 1, 4 })<<endl;
}