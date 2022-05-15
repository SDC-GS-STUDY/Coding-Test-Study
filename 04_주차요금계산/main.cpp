#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>

using namespace std;
//4_���� ��� ���

vector<string> data_Phars(string data)
{
    vector<string> p_data;
    string tmp_data;
    stringstream stream;
    stream.str(data);
    while (stream >> tmp_data) p_data.push_back(tmp_data);
    //' '�� \n�� �������� string �����͸� ������ p_data vector�� �����Ѵ�.
    //tmp_data = {�ð�, ������ȣ, ����}

    return p_data;
}

int fee_chalc(vector<int> fees,int cumul_time)
{
    //fees : �⺻�ð�, �⺻���, �����ð�, �������
    int fee = fees[1];
    if (cumul_time <= fees[0]) return fee;
    fee += ceil(float(cumul_time - fees[0]) / (float)fees[2]) * fees[3];
    return fee;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> In_Log; //���Ա��{������ȣ, �ð�}
    map<string, int> fee_data; //��ݱ��{������ȣ, �����ð�->�������}, �⺻�� ��������
    //1. use <sstream> to pharsing data
    for (auto data : records)
    {
        vector<string> dt = data_Phars(data);
        //dt[0] : �ð�
        //dt[1] : ���� ��ȣ
        //dt[2] : ����(IN, OUT)
        //cout << dt[0] <<" " << dt[1] << " " << dt[2] << endl;

        //������ ��쿡�� ���� ���Ա���� �ִ��� Ȯ�� �� ������ �����Ѵ�.
        if (dt[2] == "IN" && In_Log.find(dt[1]) == In_Log.end())
        {
            In_Log.insert({ dt[1], dt[0] });
        } //������ ���
        else if (dt[2] == "OUT" && In_Log.find(dt[1]) != In_Log.end())
        {
            //1. In_Log���� �ش� ���� ��ȣ�� �˻��Ѵ�.
            int t_in_H = stoi(In_Log[dt[1]].substr(0, 2));
            int t_in_m = stoi(In_Log[dt[1]].substr(3, 2));
            int t_out_H = stoi(dt[0].substr(0, 2));
            int t_out_m = stoi(dt[0].substr(3, 2));
           // cout << t_in_H << " " << t_in_m << " " << t_out_H << " " << t_out_m << endl;
            //�����ð�(�� ���)
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

            if (fee_data.find(dt[1]) != fee_data.end())
            {
                fee_data[dt[1]] += hour * 60 + minute;
            }
            else//ó�� ���� �����̶��?
            {
                fee_data.insert({ dt[1] ,hour * 60 + minute });
            }

            In_Log.erase(dt[1]); //���� ������ ����.
        }
    }
    
    //��������� ���� �������� Ȯ���Ͽ� �����Ѵ�.
      //��������� �ִٸ� �̹� ���Ա�Ͽ��� ���� �Ǿ�����!
    for (auto data : In_Log)
    {
        int t_in_H = stoi(data.second.substr(0, 2));
        int t_in_m = stoi(data.second.substr(3, 2));

        //�����ð�(�� ���)
        //� ������ ������ �Ŀ� ������ ������ ���ٸ�, 23:59�� ������ ������ �����մϴ�
        int hour = 23 - t_in_H;
        int minute = 59 - t_in_m;

        //�̹� ������ ���� ���� �ߴ� �����̶��?
        if (fee_data.find(data.first) != fee_data.end())
        {
            fee_data[data.first] += hour * 60 + minute;
        }
        else//ó�� ���� �������̶��?
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