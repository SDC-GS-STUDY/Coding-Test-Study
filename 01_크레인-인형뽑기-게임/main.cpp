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
        :inputBuff(_inputBuff),pckItem(0) {}

    ~User(){}

    const bool pick(vector<vector<int>>& _board) //인형뽑기에 성공하면 true, 실패하면 false
    {
        int index = inputBuff[0]; //input값 맨 앞의 위치를 지역변수에 담는다.
        inputBuff.erase(inputBuff.begin());// 담았으니까 버퍼에서 삭제해준다.

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
        if (inputBuff.empty()) //user의 인풋값 버퍼가 비면 false 리턴
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
    Machine(User* _user, vector<vector<int>> _board) 
        :user(_user), answer(0), board(_board){}

    ~Machine()
    {
        delete user;
        user = 0;
    }

    void play()
    {
        while (user->isEnd()) //user의 input stack이 empty가 될 떄 까지 반복
        {
            if (!user->pick(board)) continue; //input에 따라 user가 인형을 뽑는 데, 위치에 인형이 있으면 true, 없으면 false 반환됨.
            //안뽑혔으면 아래 명령을 수행할 필요가 없어서 continue
            //뽑혔으면, basket 확인해서 콤보인지 확인한다.
            //바구니가 비지 않은 상태에서 스택 상단과 비교.
            if (!basket.empty() && basket.top() == user->getpckItem())
            {
                basket.pop();
                answer += 2;
            }
            else
                basket.push(user->getpckItem()); //바구니가 비어있거나, 콤보가 아니면 그냥 바구니에 인형을 담는다.
            
        }

        //while문이 종료 되면 최종 값 print
        cout << answer << endl;
    }
};


int main()
{
    User* user = new User({ 1, 5, 3, 5, 1, 2, 1, 4 });
    Machine* game = new Machine(user, { {0, 0, 0, 0, 0},{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} });

    game->play();

    return 0;
}