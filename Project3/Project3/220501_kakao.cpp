#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

//맵 자체가 중복을 허용하지 않음. 
//map 은 first,second가 있는 pair로 저장되고 first = key, second = value로 저장
//unordered map은 자동으로 정렬되지 않음 
//map은 자동 정렬 
//중복되면 나란히 저장됨 

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> user; // 행동 아이디
    unordered_map<string, string> idName; // 아이디 이름 

    for (int i = 0; i < record.size(); i++) {

        vector<string> split;
        stringstream ss(record[i]); // 나뉜거 배열로 만들어 주기 
        string a; // string으로 stringstream 해주면 enter/ uid1234/ muzi 이런식으로 나뉨 
        while (ss >> a) {
            split.push_back(a);
        }
        user.push_back({ split[0], split[1] }); // 행동이랑 아이디 나누기 
        if (split[0] != "Leave") { // 만약 Leave라면 
            idName[split[1]] = split[2]; // id랑 이름 저장해주기 
            //map [key] = 변수 --> 대입 연산
            //m[key 값] 범위 검사하지 않고 key값에 대해 접근
            //m.at(key 값) 범위도 검사하면서 key 값에 대해 접근 

        }
    }

    for (int i = 0; i < record.size(); i++) {
        string result = "";
        result += idName[user[i].second]; //아이디 


        if (user[i].first == "Enter")
        {
            result += "님이 들어왔습니다."; 
        }
        else if (user[i].first == "Leave") 
        { 
            result += "님이 나갔습니다."; 
        }
        else if (user[i].first == "Change") 
        {
            continue; 
        }

        answer.push_back(result);
    }

    return answer;
}
