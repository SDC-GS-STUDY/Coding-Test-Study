#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int stringToInt_timeCalc(string currentTime, string inTime)
{
    int cHour = 0, iHour = 0, cMin = 0, iMin = 0;
    int calcHour = 0, calcMin = 0;

    stringstream stringToInt_cHour(currentTime.substr(0, 2)); // 0��°���� 2��
    stringToInt_cHour >> cHour;

    stringstream stringToInt_iHour(inTime.substr(0, 2));
    stringToInt_iHour >> iHour;

    stringstream stringToInt_cMin(currentTime.substr(3, 2)); // 3��°���� 2��
    stringToInt_cMin >> cMin;

    stringstream stringToInt_iMin(inTime.substr(3.2));
    stringToInt_iMin >> iMin;


    // �� ������ ���
    calcHour = (cHour - iHour) * 60;
    calcMin = cMin - iMin;

    return calcHour + calcMin;
}


// fees_len�� �迭 fees�� �����Դϴ�.
// records_len�� �迭 records�� �����Դϴ�.
// �Ķ���ͷ� �־����� ���ڿ��� const�� �־����ϴ�. �����Ϸ��� ���ڿ��� �����ؼ� ����ϼ���.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) 
{
    // return ���� malloc �� ���� �Ҵ��� ������ּ���. �Ҵ� ���̴� ��Ȳ�� �°� �������ּ���.
    int* answer = (int*)malloc(sizeof(int));

    map<string, int> parkingTimeMap; // ���� ��ȣ, �ð� ��� ��
    map<string, string> parkingMap; // ���� ��ȣ, inout�ð�
    map<string, int> resultMap; // ���� ��ȣ, �� ��� ��

    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    

    for (int i = 0; i < records_len; i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut; // ����������� �߶� ����
        
        if (inOut == "IN")
        {
            parkingMap[number] = time; // �ش� ������ȣ�� �ð� �ֱ�, ������ out�ϸ� ��갪 �����ϰ� ����Ŷ� ��������� ���� �������ʿ����
        }
        else if (inOut == "OUT") // ���� �� ��� �� �ֱ�
        {
            // �ð� �����ϱ�
            parkingTimeMap[number] += stringToInt_timeCalc(time, parkingMap[number]); // ���� �ð� - �ش� ���� in ���� �� �ð�

            parkingMap[number].erase(); // �����ϸ� ��� �����
        }
    }

    // record �� ���� ���� ���� ���� �߰� ���
    // ���� ��ȣ, inout�ð��� �������� ���� �͸� ã�����ؼ� map�� iterator�� ����
    for (map<string, string>::iterator it = parkingMap.begin(); it != parkingMap.end(); ++it)
    {
        // it->first ==> MAP ���� ���� ��(key), it->second ==> MAP���� ������ ��(Value)
        parkingTimeMap[it->first] += stringToInt_timeCalc(it->second, "23:59");
    }


    for (int i = 0; i < records_len; i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut;

        if (parkingTimeMap[number] <= basicTime) // �⺻ ��ݺ��� ������
        {
            resultMap[number] += basicFee; // �⺻ ��� �ֱ�
        }
        else if (parkingTimeMap[number] > basicTime)
        {
            // ���� ��� * ((������ �ð� - �⺻ �ð�)  / �ð� ����)
            resultMap[number] += unitFee * ((parkingTimeMap[number] - basicTime) / unitTime); 
        }
    }

    // resultMap ��ȯ�Ͽ� ����� ����
    for (map<string, int>::iterator it = resultMap.begin(); it != resultMap.end(); ++it)
    {
        int i = 0;

        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut;

        answer += resultMap[number];

        i++;
    }

    return answer;
}

int main()
{

    return 0;
}