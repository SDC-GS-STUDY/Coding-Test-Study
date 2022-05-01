#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {

    vector<string> answer;

    vector<string> id; // id ���� ����

    string s;

    if (record[0] == "Enter")
    {
        s = record.back(); // �г��� ��ȯ

        // ��� ���Ϳ� �߰�
        answer.push_back(s);
        answer.push_back("���� ���Խ��ϴ�");

        id.push_back(record[1]); // id ����
    }
    else if (record[0] == "Leave")
    {
        for (int i = 0; i < id.size(); i++)
        {
            if (id[i] == record[i]) // id�� �ִٸ�
            {
                s = record.back(); // �г��� ��ȯ

                // ��� ���Ϳ� �߰�
                answer.push_back(s);
                answer.push_back("���� �������ϴ�");

                id.pop_back(); // id ����
            }
            else // ���̵� ���ٸ�
            {
                // �ƹ��͵� ����
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
    getline(cin, s); // �������� ���ڿ� �ޱ�

    stringstream temp(s);

    string split;

    while (temp >> split)
    {
        answer.push_back(split); // ���Ϳ� �ֱ�
        //cout << split << endl;
    }

    solution(answer);// ���� ���� ������ �ֱ�

    return 0;
}