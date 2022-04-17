#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class User
{
private:
   vector<int> inputBuff; //moves
   int pckItem;//뽑은 인형
public:
    User(vector<int> _inputBuff)
        :inputBuff(_inputBuff),pckItem(0)
    {

    }

    bool pick(vector<vector<int>>& _board) //인형뽑기에 성공하면 true, 실패하면 false
    {
        int index = inputBuff[0];
        inputBuff.erase(inputBuff.begin());

        for (int i = 0; i < _board.size(); i++)
        {
            if (_board[i][index - 1] != 0)//행[열index] 로 비어있지 않으면
            {
                int ret; //return 값 임시 저장
                pckItem = _board[i][index - 1];
                _board[i][index - 1] = 0;//꺼내졌으므로 해당자리는 0

                return true;//리턴!
            }
        }
        return false;
    }

    const int getpckItem() { return pckItem; }

    const bool isEnd()
    {
        if (inputBuff.empty())
            return false;
        return true;
    }
};

class Machine
{
private:
    vector<vector<int>> board;
    stack<int> basket;
    
    User* user;

    int answer;
public:
    Machine(User* _user, vector<vector<int>> _board):user(_user),answer(0)
    {
        board = _board;
    }

    void update()
    {
        while (user->isEnd())
        {
            if (!user->pick(board)) continue;

            if (!basket.empty() && basket.top() == user->getpckItem())
            {
                basket.pop();
                answer += 2;
            }
            else
                basket.push(user->getpckItem());
            
        }

        cout << answer << endl;
    }
};


int main()
{
    User* user = new User({ 1, 5, 3, 5, 1, 2, 1, 4 });
    Machine* game = new Machine(user, { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} });

    game->update();
}