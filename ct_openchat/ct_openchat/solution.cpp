#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;
    map<string, string> map;

    // id�� key������ ��� �̸��� �Է� Ȥ�� ����Ǿ� map�� ������
    for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
    {
        stringstream ss(*it);
        string command, id, name;

        ss >> command; // �ڷ����� ������ �������� ������ ��������, �ѹ� �߷���

        if (command == "Enter") // Enter���
        {
            ss >> id >> name; // id�� name���� �ڸ�
            map[id] = name; // id�� key������ name value �߰�
        }
        else if (command == "Change")
        {
            ss >> id >> name;
            map[id] = name; // id�� key������ �����
        }
    }

    for (vector<string>::iterator it = record.begin(); it != record.end(); ++it)
    {
        stringstream ss(*it);
        string command, id, name;

        ss >> command;

        if (command == "Enter")
        {
            ss >> id; // id�� map���� �о�;���
            answer.push_back(map[id] + "���� ���Խ��ϴ�.");
        }
        else if (command == "Leave")
        {
            ss >> id;
            answer.push_back(map[id] + "���� �������ϴ�.");
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