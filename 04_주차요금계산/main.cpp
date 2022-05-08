#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;
//4_주차 요금 계산

vector<string> data_Phars(string data)
{
    vector<string> p_data;
    string tmp_data;
    stringstream stream;
    stream.str(data);
    while (stream >> tmp_data) p_data.push_back(tmp_data);
    //' '과 \n을 기준으로 string 데이터를 나누어 p_data vector에 삽입한다.
    //tmp_data = {시각, 차량번호, 내역}

    return p_data;
}

int fee_chalc(vector<int> fees,int cumul_time)
{
    //fees : 기본시간, 기본요금, 단위시간, 단위요금
    int fee = fees[1];
    if (cumul_time <= fees[0]) return fee;
    fee += ceil(float(cumul_time - fees[0]) / (float)fees[2]) * fees[3];
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> In_Log; //출입기록{차량번호, 시간}
    map<string, int> fee_data; //요금기록{차량번호, 누적시간->주차요금}, 기본이 오름차순
    //1. use <sstream> to pharsing data
    for (auto data : records)
    {
        vector<string> dt = data_Phars(data);
        //dt[0] : 시간
        //dt[1] : 차량 번호
        //dt[2] : 내역(IN, OUT)
        //cout << dt[0] <<" " << dt[1] << " " << dt[2] << endl;

        //출입일 경우에는 이전 출입기록이 있는지 확인 후 없으면 저장한다.
        if (dt[2] == "IN" && In_Log.find(dt[1]) == In_Log.end())
        {
            In_Log.insert({ dt[1], dt[0] });
        } //출차일 경우
        else if (dt[2] == "OUT" && In_Log.find(dt[1]) != In_Log.end())
        {
            //1. In_Log에서 해당 차량 번호를 검색한다.
            int t_in_H = stoi(In_Log[dt[1]].substr(0, 2));
            int t_in_m = stoi(In_Log[dt[1]].substr(3, 2));
            int t_out_H = stoi(dt[0].substr(0, 2));
            int t_out_m = stoi(dt[0].substr(3, 2));
           // cout << t_in_H << " " << t_in_m << " " << t_out_H << " " << t_out_m << endl;
            //누적시간(분 계산)
            int hour;
            int minute;
            if (t_in_m >= t_out_m)
            {
                minute = t_out_m + 60 - t_in_m;
                hour = t_out_H - t_in_H - 1;
            }
            else
            {
                minute = t_out_m - t_in_m;
                hour = t_out_H - t_in_H;
            }

            fee_data.insert({ dt[1] ,hour * 60 + minute });

            In_Log.erase(dt[1]); //출차 했으면 삭제.
        }
    }
    
    //출차기록이 없는 차량들을 확인하여 저장한다.
      //출차기록이 있다면 이미 출입기록에서 삭제 되어있음!
    for (auto data : In_Log)
    {
        int t_in_H = stoi(data.second.substr(0, 2));
        int t_in_m = stoi(data.second.substr(3, 2));

        //누적시간(분 계산)
        //어떤 차량이 입차된 후에 출차된 내역이 없다면, 23:59에 출차된 것으로 간주합니다
        int hour = 23 - t_in_H;
        int minute = 59 - t_in_m;

        //이미 예전에 출입 출차 했던 차량이라면?
        if (fee_data.find(data.first) != fee_data.end())
        {
            fee_data[data.first] += hour * 60 + minute;
            int tmep = fee_data[data.first];
            int i = 10;
        }
        else//처음 들어오 ㄴ차량이라면?
        {
            fee_data.insert({ data.first ,hour * 60 + minute });
        }
    }

    for (auto fee : fee_data)
    {
        answer.push_back(fee_chalc(fees, fee.second));
    }
    return answer;
}

int main()
{
    solution({ 180, 5000, 10, 600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
   // solution({ 180, 5000, 10, 600 },{ "05:34 5961 IN", "06:34 5961 OUT", "07:34 5961 IN", "08:34 5961 OUT", "09:34 5961 IN", "10:34 5961 OUT", "11:34 5961 IN", "12:34 5961 OUT" });
    return 0;
}