#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;


// 누적 시간 계산
int timeCulator(string IN, string OUT) {
    int hourIN = stoi(IN.substr(0, 2));
    int minuteIN = stoi(IN.substr(3, 2));
    int hourOUT = stoi(OUT.substr(0, 2));
    int minuteOUT = stoi(OUT.substr(3, 2));

    int accumlateTime = (hourOUT - hourIN) * 60 + (minuteOUT - minuteOUT);

    return accumlateTime;
    
}


vector<int> solution(vector<int>fees, vector<string>records) {
    vector<int> answer; // 이것도 동적할당이니까 -> 총 요금
    map<string, vector<string>> parkingMap; // key (차량번호) - value (시간 => 이걸로 총 요금 계산)
    stringstream ss;

    // ranged-base for문 (변수에 배열을 반복적으로 할당)
    for (auto record : records) {
        ss.str(record);
        string time, carNumber, state;
        ss >> time >> carNumber >> state; // records에서 빼낸 record를 ss에 extraction
        parkingMap[carNumber].push_back(time); // key - value 완성
        ss.clear(); // records 한 번 돌고 나서는 다시 지워야 함
    }

    for (auto judgingINOUT : parkingMap) {
        if (judgingINOUT.second.size() & 1) {
            judgingINOUT.second.push_back("23:59");
        }
        vector<string>info = judgingINOUT.second;
        int totalTime = 0;
        for (int i = 0; i < info.size() - 1; i += 2) {
            totalTime += timeCulator(info[i], info[i + 1]);
        }
        int price = fees[1];
        if (totalTime > fees[0])
            price += ceil((totalTime - fees[0]) / (double)fees[2]) * fees[3];
        answer.push_back(price);
    }


    return answer;
}