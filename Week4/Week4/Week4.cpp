#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer;
    map<string, string> state;
    map<string, int> list;
    for (auto it : records)
    {
        istringstream iss(it);
        string tmp[3];
        string token;
        int index = 0;
        while (getline(iss, token, ' '))
        {
            tmp[index++] = token;
        }

        if (tmp[2] == "IN")
        {
            state[tmp[1]] = tmp[0];
            list[tmp[1]]++;
        }
        
        else //out
        {
            istringstream st(tmp[0]);
            string time[4];  //0 1 출차 2 3 입차
            index = 0;
            int sum = 0;
            while (getline(st, token, ':'))
            {
                time[index++] = token;
            }

            sum = stoi(time[0]) * 60 + stoi(time[1]) - stoi(time[2]) * 60 - stoi(time[3]);
            if (sum > 180)
            {
                int value = fees[1] + ((sum - fees[0]) / 10 * fees[2]);
                answer.push_back(value);
            }

            else
                answer.push_back(fees[1]);
            list[tmp[1]]--;
        }
    }

    for (auto it : list)
    {
        it.second = 3;
    }

    return answer;
}