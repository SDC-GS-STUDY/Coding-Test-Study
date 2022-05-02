#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;

    vector<string> id; // id 저장 벡터

    string s;

    if (record[0] == "Enter")
    {
        s = record.back(); // 닉네임 반환

        // 답안 벡터에 추가
        answer.push_back(s);
        answer.push_back("님이 들어왔습니다");

        id.push_back(record[1]); // id 저장
    }
    else if (record[0] == "Leave")
    {
        for (int i = 0; i < id.size(); i++)
        {
            if (id[i] == record[i]) // id가 있다면
            {
                s = record.back(); // 닉네임 반환

                // 답안 벡터에 추가
                answer.push_back(s);
                answer.push_back("님이 나갔습니다");

                id.pop_back(); // id 삭제
            }
            else // 아이디가 없다면
            {
                // 아무것도 안함
            }
        }
    }
    else if (record[0] == "Change")
    {
        
    }

    return answer;
}

int main()
{
    vector<string> answer;

    string s;
    getline(cin, s); // 공백포함 문자열 받기

    stringstream temp(s);

    string split;

    while (temp >> split)
    {
        answer.push_back(split); // 벡터에 넣기
        //cout << split << endl;
    }

    solution(answer);// 드디어 벡터 문제에 넣기

    return 0;
}