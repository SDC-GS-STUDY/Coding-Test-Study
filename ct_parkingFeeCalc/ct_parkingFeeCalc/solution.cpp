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

    stringstream stringToInt_cHour(currentTime.substr(0, 2)); // 0번째부터 2개
    stringToInt_cHour >> cHour;

    stringstream stringToInt_iHour(inTime.substr(0, 2));
    stringToInt_iHour >> iHour;

    stringstream stringToInt_cMin(currentTime.substr(3, 2)); // 3번째부터 2개
    stringToInt_cMin >> cMin;

    stringstream stringToInt_iMin(inTime.substr(3.2));
    stringToInt_iMin >> iMin;


    // 분 단위로 계산
    calcHour = (cHour - iHour) * 60;
    calcMin = cMin - iMin;

    return calcHour + calcMin;
}


// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) 
{
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int));

    map<string, int> parkingTimeMap; // 차량 번호, 시간 계산 값
    map<string, string> parkingMap; // 차량 번호, inout시각
    map<string, int> resultMap; // 차량 번호, 총 계산 값

    int basicTime = fees[0];
    int basicFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    

    for (int i = 0; i < records_len; i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut; // 공백기준으로 잘라서 넣음
        
        if (inOut == "IN")
        {
            parkingMap[number] = time; // 해당 차량번호에 시각 넣기, 어차피 out하면 계산값 누적하고 지울거라 덮어씌워지는 문제 생각할필요없음
        }
        else if (inOut == "OUT") // 나갈 때 계산 값 넣기
        {
            // 시간 누적하기
            parkingTimeMap[number] += stringToInt_timeCalc(time, parkingMap[number]); // 현재 시각 - 해당 차량 in 했을 때 시각

            parkingMap[number].erase(); // 출차하면 기록 지우기
        }
    }

    // record 다 돌고 출차 안한 차량 추가 계산
    // 차량 번호, inout시각이 지워지지 않은 것만 찾기위해서 map을 iterator로 돌아
    for (map<string, string>::iterator it = parkingMap.begin(); it != parkingMap.end(); ++it)
    {
        // it->first ==> MAP 에서 왼쪽 값(key), it->second ==> MAP에서 오른쪽 값(Value)
        parkingTimeMap[it->first] += stringToInt_timeCalc(it->second, "23:59");
    }


    for (int i = 0; i < records_len; i++)
    {
        stringstream ss(records[i]);
        string time, number, inOut;

        ss >> time >> number >> inOut;

        if (parkingTimeMap[number] <= basicTime) // 기본 요금보다 적으면
        {
            resultMap[number] += basicFee; // 기본 요금 넣기
        }
        else if (parkingTimeMap[number] > basicTime)
        {
            // 단위 요금 * ((주차한 시간 - 기본 시간)  / 시간 단위)
            resultMap[number] += unitFee * ((parkingTimeMap[number] - basicTime) / unitTime); 
        }
    }

    // resultMap 순환하여 결과값 저장
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