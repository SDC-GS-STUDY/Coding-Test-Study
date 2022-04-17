#include <string>
#include <vector>

using namespace std;

class doll
{ 
public:int solution(vector<vector<int>> board, vector<int> moves) {
        int answer = 0;
        vector<int> basket;

        for (int i = 0; i < moves.size(); i++)
        {
            int empty = 0, value;
            for (int j = 0; j < board.size(); j++)
            {
                value = board[j][moves[i] - 1];

                if (value == 0)
                {
                    empty++;
                }
                else
                    break;
            }


            if (empty < board.size())
            {
                basket.push_back(value);
                board[empty][moves[i] - 1] = 0;

                if (basket.size() >= 2 && value == basket[basket.size() - 2])
                {
                    basket.pop_back();
                    basket.pop_back();
                    answer += 2;
                }
            }
        }
        return answer;
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> basket;

    for (int i = 0; i < moves.size(); i++) 
    {
        int empty = 0, value;
        for (int j = 0; j < board.size(); j++) 
        {
            value = board[j][moves[i] - 1];

            if (value == 0)
            {
                empty++;
            }
            else 
                break;
        }


        if (empty < board.size()) 
        {
            basket.push_back(value);
            board[empty][moves[i] - 1] = 0;

            if (basket.size() >= 2 && value == basket[basket.size() - 2]) 
            {
                basket.pop_back();
                basket.pop_back();
                answer += 2;
            }
        }
    }
    return answer;
}