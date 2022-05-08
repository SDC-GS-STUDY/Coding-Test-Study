#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

//�� ��ü�� �ߺ��� ������� ����. 
//map �� first,second�� �ִ� pair�� ����ǰ� first = key, second = value�� ����
//unordered map�� �ڵ����� ���ĵ��� ���� 
//map�� �ڵ� ���� 
//�ߺ��Ǹ� ������ ����� 

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<pair<string, string>> user; // �ൿ ���̵�
    unordered_map<string, string> idName; // ���̵� �̸� 

    for (int i = 0; i < record.size(); i++) {

        vector<string> split;
        stringstream ss(record[i]); // ������ �迭�� ����� �ֱ� 
        string a; // string���� stringstream ���ָ� enter/ uid1234/ muzi �̷������� ���� 
        while (ss >> a) {
            split.push_back(a);
        }
        user.push_back({ split[0], split[1] }); // �ൿ�̶� ���̵� ������ 
        if (split[0] != "Leave") { // ���� Leave��� 
            idName[split[1]] = split[2]; // id�� �̸� �������ֱ� 
            //map [key] = ���� --> ���� ����
            //m[key ��] ���� �˻����� �ʰ� key���� ���� ����
            //m.at(key ��) ������ �˻��ϸ鼭 key ���� ���� ���� 

        }
    }

    for (int i = 0; i < record.size(); i++) {
        string result = "";
        result += idName[user[i].second]; //���̵� 


        if (user[i].first == "Enter")
        {
            result += "���� ���Խ��ϴ�."; 
        }
        else if (user[i].first == "Leave") 
        { 
            result += "���� �������ϴ�."; 
        }
        else if (user[i].first == "Change") 
        {
            continue; 
        }

        answer.push_back(result);
    }

    return answer;
}
