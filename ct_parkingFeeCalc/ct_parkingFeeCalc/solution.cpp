#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <cmath>

using namespace std;


int convert(string time)
{
    string hour = time.substr(0, 2);
    string min = time.substr(3, 2);
    return stoi(hour) * 60 + stoi(min);
}

// fees_len�� �迭 fees�� �����Դϴ�.
// records_len�� �迭 records�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
// int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) 
vector<int> solution(vector<int> fees, vector<string> records)
{
    vector<int> answer; // ��� ���

    map<string, int> parkingTimeMap; // ���� ��ȣ, �ð�
    map<string, int> resultMap; // ���� ��ȣ, �� �̿�ð�(��) ��� ��

    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];    

    for (int i = 0; i < records.size(); i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut; // ����������� �߶� ����
        
        if (inOut == "IN")
        {
            parkingTimeMap[number] = convert(time); // �ش� ������ȣ�� �ð�(�д����� ��ȯ) ��
        }
        else if (inOut == "OUT") // ���� �� ��� �� �ֱ�
        {
            // ��� �ʿ� �����ð� - �����ð�
            resultMap[number] += convert(time) - parkingTimeMap[number];

            parkingTimeMap.erase(number); // �����ϸ� ��� �����
        }
    }

    // record �� ���� ���� ���� ���� �߰� ���
    // ���� ��ȣ, inout�ð��� �������� ���� �͸� ã�����ؼ� map�� iterator�� ����
    for (map<string, int>::iterator it = parkingTimeMap.begin(); it != parkingTimeMap.end(); ++it)
    {
        // 23:59�̶� ġ�� ���� �ð� �д����� ���� �־��ֱ�
        resultMap[it->first] += 23 * 60 + 59 - it->second;
    }

    // ��� �ð��� �ԷµǾ��ִ� �� resultMap
    for (map<string, int>::iterator it = resultMap.begin(); it != resultMap.end(); ++it)
    {
        // �⺻�ð����� ������
        if (it->second <= basicTime)
        {
            answer.push_back(basicFee);
        }
        else
        {
            // ������ �Ǽ��� �ϱ� ���� double�ƹ��볪 �ֱ�
            answer.push_back(basicFee + ceil((double)(it->second - basicTime) / unitTime) * unitFee);
        }
    }

    return answer;
}

int main()
{
    vector<int> v1;
    vector<string> v2;

#pragma region INPUT
    v1.push_back(180);
    v1.push_back(5000);
    v1.push_back(10);
    v1.push_back(600);

    v2.push_back("05:34 5961 IN");
    v2.push_back("06:00 0000 IN");
    v2.push_back("06:34 0000 OUT");
    v2.push_back("07:59 5961 OUT");
    v2.push_back("07:59 0148 IN");
    v2.push_back("18:59 0000 IN");
    v2.push_back("19:09 0148 OUT");
    v2.push_back("22:59 5961 IN");
    v2.push_back("23:00 5961 OUT");
#pragma endregion
    
    vector<int> sol = solution(v1, v2);

    for (vector<int>::iterator it = sol.begin(); it != sol.end(); ++it)
    {
       cout << (*it) << endl;
    }

    return 0;
}