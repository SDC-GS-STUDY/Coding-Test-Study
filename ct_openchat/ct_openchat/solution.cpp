#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;
    map<string, string> map;

    // id를 key값으로 모든 이름이 입력 혹은 변경되어 map을 구성함
    for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
    {
        stringstream ss(*it);
        string command, id, name;

        ss >> command; // 자료형의 공백을 기준으로 나눠서 저장해줌, 한번 잘려짐

        if (command == "Enter") // Enter라면
        {
            ss >> id >> name; // id랑 name으로 자름
            map[id] = name; // id를 key값으로 name value 추가
        }
        else if (command == "Change")
        {
            ss >> id >> name;
            map[id] = name; // id를 key값으로 덮어씌움
        }
    }

    for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
    {
        stringstream ss(*it);
        string command, id, name;

        ss >> command;

        if (command == "Enter")
        {
            ss >> id; // id를 map에서 읽어와야함
            answer.push_back(map[id] + "님이 들어왔습니다.");
        }
        else if (command == "Leave")
        {
            ss >> id;
            answer.push_back(map[id] + "님이 나갔습니다.");
        }
    }

    return answer;
}

int main()
{
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");

    vector<string> sol = solution(record);

    for (vector<string>::iterator it = sol.begin(); it != sol.end(); ++it)
    {
        cout << (*it) << endl;
        
    }

    return 0;
}