#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

class User
{
private:
   vector<int> inputBuff; //moves
   int pckItem;//���� ����
public:
    User(vector<int> _inputBuff)
        :inputBuff(_inputBuff),pckItem(0) {}

    ~User(){}

    const bool pick(vector<vector<int>>& _board) //�����̱⿡ �����ϸ� true, �����ϸ� false
    {
        int index = inputBuff[0]; //input�� �� ���� ��ġ�� ���������� ��´�.
        inputBuff.erase(inputBuff.begin());// ������ϱ� ���ۿ��� �������ش�.

        for (int i = 0; i < _board.size(); i++)
        {
            if (_board[i][index - 1] != 0)//��[��index] �� ������� ������
            {
                int ret; //return �� �ӽ� ����
                pckItem = _board[i][index - 1];
                _board[i][index - 1] = 0;//���������Ƿ� �ش��ڸ��� 0

                return true;//����!
            }
        }
        return false;
    }

    const int getpckItem() { return pckItem; }

    const bool isEnd()
    {
        if (inputBuff.empty()) //user�� ��ǲ�� ���۰� ��� false ����
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
        while (user->isEnd()) //user�� input stack�� empty�� �� �� ���� �ݺ�
        {
            if (!user->pick(board)) continue; //input�� ���� user�� ������ �̴� ��, ��ġ�� ������ ������ true, ������ false ��ȯ��.
            //�Ȼ������� �Ʒ� ����� ������ �ʿ䰡 ��� continue
            //��������, basket Ȯ���ؼ� �޺����� Ȯ���Ѵ�.
            //�ٱ��ϰ� ���� ���� ���¿��� ���� ��ܰ� ��.
            if (!basket.empty() && basket.top() == user->getpckItem())
            {
                basket.pop();
                answer += 2;
            }
            else
                basket.push(user->getpckItem()); //�ٱ��ϰ� ����ְų�, �޺��� �ƴϸ� �׳� �ٱ��Ͽ� ������ ��´�.
            
        }

        //while���� ���� �Ǹ� ���� �� print
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