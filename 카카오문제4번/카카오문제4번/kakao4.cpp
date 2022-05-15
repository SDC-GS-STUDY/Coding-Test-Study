#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>

using namespace std;


// ���� �ð� ���
int timeCulator(string IN, string OUT) {
    int hourIN = stoi(IN.substr(0, 2));
    int minuteIN = stoi(IN.substr(3, 2));
    int hourOUT = stoi(OUT.substr(0, 2));
    int minuteOUT = stoi(OUT.substr(3, 2));

    int accumlateTime = (hourOUT - hourIN) * 60 + (minuteOUT - minuteOUT);

    return accumlateTime;
    
}


vector<int> solution(vector<int>fees, vector<string>records) {
    vector<int> answer; // �̰͵� �����Ҵ��̴ϱ� -> �� ���
    map<string, vector<string>> parkingMap; // key (������ȣ) - value (�ð� => �̰ɷ� �� ��� ���)
    stringstream ss;

    // ranged-base for�� (������ �迭�� �ݺ������� �Ҵ�)
    for (auto record : records) {
        ss.str(record);
        string time, carNumber, state;
        ss >> time >> carNumber >> state; // records���� ���� record�� ss�� extraction
        parkingMap[carNumber].push_back(time); // key - value �ϼ�
        ss.clear(); // records �� �� ���� ������ �ٽ� ������ ��
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