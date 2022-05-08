#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, state;
    map<string, string> user; // ID, Nickname

    for (int i = 0; i < record.size(); i++) {
        string str[3]; // state, ID, Nickname
        string token; // token 분리
        stringstream tokenString(record[i]); // record 문자열 파싱
        int index = 0; 

        // >> 연산자 = 토큰분리 (스페이스 바 기준)
        while (tokenString >> token) {
            str[index] = token;
            index++;
        }

        // Enter
        if (str[0] == "Enter") {
            state.push_back("님이 들어왔습니다."); // push_back = vector 끝에 추가
            answer.push_back(str[1]); // answer에는 ID가 저장돼야 하므로 저장
            user[str[1]] = str[2]; // 해당 ID에 Nickname 저장
        }
        // Leave
        else if (str[0] == "Leave") {
            state.push_back("님이 나갔습니다.");
            answer.push_back(str[1]);
        }
        // Change
        else
            user[str[1]] = str[2];
    }

    for (int i = 0; i < answer.size(); i++) {
        answer[i] = user[answer[i]] + state[i];
    }

    return answer;
}