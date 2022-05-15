// https://www.lifencoding.com/language/22?p=1 에서 문자열 쪼개는거 힌트 얻음
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> state;
    map<string, string> list;

    for (auto its : record)
    {
        int index = 0;
        string tmp[3];
        string token;
        istringstream st(its);
        while (getline(st, token, ' '))
        {
            tmp[index++] = token;
        }

        if (tmp[0] == "Enter")
        {
            list[tmp[1]] = tmp[2];
            answer.push_back(tmp[1]);
            state.push_back("님이 들어왔습니다.");
        }

        else if (tmp[0] == "Leave")
        {
            answer.push_back(tmp[1]);
            state.push_back("님이 나갔습니다.");
        }

        else //change
        {
            list[tmp[1]] = tmp[2];
        }
    }

    int len = answer.size();
    for (int i = 0; i < len; i++)
    {
        answer[i] = list[answer[i]] + state[i];
    }

    return answer;
}