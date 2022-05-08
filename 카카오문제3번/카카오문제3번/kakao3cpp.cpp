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
        string token; // token �и�
        stringstream tokenString(record[i]); // record ���ڿ� �Ľ�
        int index = 0; 

        // >> ������ = ��ū�и� (�����̽� �� ����)
        while (tokenString >> token) {
            str[index] = token;
            index++;
        }

        // Enter
        if (str[0] == "Enter") {
            state.push_back("���� ���Խ��ϴ�."); // push_back = vector ���� �߰�
            answer.push_back(str[1]); // answer���� ID�� ����ž� �ϹǷ� ����
            user[str[1]] = str[2]; // �ش� ID�� Nickname ����
        }
        // Leave
        else if (str[0] == "Leave") {
            state.push_back("���� �������ϴ�.");
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