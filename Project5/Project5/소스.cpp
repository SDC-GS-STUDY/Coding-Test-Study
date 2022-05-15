#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int timeChange(string in, string out) {
    int hour = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2)); //�ð�
    int min = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2)); //��

    //substr -> string.substr(start,length)
    //���ڿ� �� ù��° ����(start)�������� �ι�° ����(length)������ ������ �ش��ϴ� ���ڿ��� ��ȯ�Ѵ�. 
    //length�� �������� ������ start�������� ���ڿ� ��ü�� ó���������� �����Ѵ�.
    //start�� ����� ���, ������ ���� ���� ������ ���ڿ��� ���ϵȴ�.
    //start�� ������ ���, start�� index�� ���ڿ��� �ڿ������� ���۵ȴ�.

    int result = hour * 60 + min;
    return result;
    //�ð� x 60�ؼ� ������ ������ְ� �е� ���̸� �����༭ ���̰��� ����� �޾��ش�. 
}



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> temp;

    map<string, vector<string>> a; //��ȣ , �ð�[] 1234/ 12:00 
    map<string, int> b;



    for (int i = 0; i < records.size(); i++) {

        stringstream ss(records[i]);
        string tmp;

        vector<string> info;

        while (ss >> tmp)
            info.push_back(tmp);

        if (info[2] == "IN") {
            a[info[1]].push_back(info[0]);
        }

        //out

        else {
            string out_time = info[0];
            string in_time = a[info[1]].back();
            a[info[1]].pop_back();
            int a = timeChange(out_time, in_time);
            b[info[1]] += a;
        }
    }




    sort(temp.begin(), temp.end());

    for (int i = 0; i < temp.size(); i++)
        answer.push_back(temp[i].second);
    return answer;
}
