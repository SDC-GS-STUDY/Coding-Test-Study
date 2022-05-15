#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>
#include <algorithm>

using namespace std;

int timeChange(string in, string out) {
    int hour = stoi(out.substr(0, 2)) - stoi(in.substr(0, 2)); //시간
    int min = stoi(out.substr(3, 2)) - stoi(in.substr(3, 2)); //분

    //substr -> string.substr(start,length)
    //문자열 중 첫번째 인자(start)에서부터 두번째 인자(length)까지의 구간에 해당하는 문자열을 반환한다. 
    //length를 지정하지 않으면 start에서부터 문자열 전체를 처리구간으로 간주한다.
    //start가 양수일 경우, 문자의 길이 보다 작으면 빈문자열이 리턴된다.
    //start가 음수일 경우, start의 index는 문자열의 뒤에서부터 시작된다.

    int result = hour * 60 + min;
    return result;
    //시간 x 60해서 분으로 만들어주고 분도 차이를 더해줘서 차이값을 결과로 받아준다. 
}



vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<pair<string, int>> temp;

    map<string, vector<string>> a; //번호 , 시간[] 1234/ 12:00 
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
