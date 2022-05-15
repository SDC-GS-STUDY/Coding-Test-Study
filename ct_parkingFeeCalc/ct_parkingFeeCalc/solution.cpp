#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;


int convert(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    return stoi(hour) * 60 + stoi(min);
}

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
// int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) 
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer; // 요금 계산

    map<string, int> parkingTimeMap; // 차량 번호, 시간
    map<string, int> resultMap; // 차량 번호, 총 이용시간(분) 계산 값

    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];    

    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut; // 공백기준으로 잘라서 넣음
        
        if (inOut == "IN")
        {
            parkingTimeMap[number] = convert(time); // 해당 차량번호에 시각(분단위로 전환) 넣
        }
        else if (inOut == "OUT") // 나갈 때 계산 값 넣기
        {
            // 결과 맵에 출차시간 - 입차시간
            resultMap[number] += convert(time) - parkingTimeMap[number];

            parkingTimeMap.erase(number); // 출차하면 기록 지우기
        }
    }

    // record 다 돌고 출차 안한 차량 추가 계산
    // 차량 번호, inout시각이 지워지지 않은 것만 찾기위해서 map을 iterator로 돌아
    for (map<string, int>::iterator it = parkingTimeMap.begin(); it != parkingTimeMap.end(); ++it)
    {
        // 23:59이라 치고 입차 시간 분단위로 빼서 넣어주기
        resultMap[it->first] += 23 * 60 + 59 - it->second;
    }

    // 모든 시간이 입력되어있는 맵 resultMap
    for (map<string, int>::iterator it = resultMap.begin(); it != resultMap.end(); ++it)
    {
        // 기본시간보다 작으면
        if (it->second <= basicTime)
        {
            answer.push_back(basicFee);
        }
        else
        {
            // 정수를 실수로 하기 위해 double아무대나 넣기
            answer.push_back(basicFee + ceil((double)(it->second - basicTime) / unitTime) * unitFee);
        }
    }

    return answer;
}

int main()
{
    vector<int> v1;
    vector<string> v2;

#pragma region INPUT
    v1.push_back(180);
    v1.push_back(5000);
    v1.push_back(10);
    v1.push_back(600);

    v2.push_back("05:34 5961 IN");
    v2.push_back("06:00 0000 IN");
    v2.push_back("06:34 0000 OUT");
    v2.push_back("07:59 5961 OUT");
    v2.push_back("07:59 0148 IN");
    v2.push_back("18:59 0000 IN");
    v2.push_back("19:09 0148 OUT");
    v2.push_back("22:59 5961 IN");
    v2.push_back("23:00 5961 OUT");
#pragma endregion
    
    vector<int> sol = solution(v1, v2);

    for (vector<int>::iterator it = sol.begin(); it != sol.end(); ++it)
    {
       cout << (*it) << endl;
    }

    return 0;
}