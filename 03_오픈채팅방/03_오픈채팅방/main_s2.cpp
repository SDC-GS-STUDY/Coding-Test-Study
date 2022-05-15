#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
//2번쨰 시도: STL map을 사용해서 재도전!!

pair<string,string> getData(string des,int type)
{
	vector<string> result;

	string s;
	stringstream stream(des);
	
	while (stream >> s) result.push_back(s);

	switch (type)
	{
	case 0:
		return { result[0], result[1] }; //{state, uID)
		break;
	case 1:
		if(result[0] == "Leave") return { result[1], "NONE" }; //{uID, name)
		return { result[1], result[2] }; //{uID, name)
		break; 
	}
	
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	map<string, string> user_info;

	//User ID에 따른 info log data를 map에 저장한다.
	for (auto data : record)
	{
		if (user_info.empty())
		{
			user_info.insert(getData(data, 1)); //map이 비어있다면 insert 한다.
			continue;
		}
		// 질문 : empty check 가 꼭 필요한가?
		
		if (user_info.find(getData(data,1).first) != user_info.end()) //info에 이미 기록이 있을경우
		{
			//기록이 있다면 Leave와 Change일 경우가 있다.
			pair<string, string> tmpDT = getData(data, 0);//{state, uID)
			if (tmpDT.first == "Change")
			{
				user_info[tmpDT.second] = getData(data, 1).second;
			}
			else if (tmpDT.first == "Enter" && user_info[tmpDT.second] != getData(data, 1).second)
			{
				user_info[tmpDT.second] = getData(data, 1).second;
			}
		}
		else //없을경우는 무조건 입장일 경우 밖에 없다.
		{
			user_info.insert(getData(data, 1));
		}
	}

	//Printing Result

	for (auto data : record)
	{
		pair<string, string> tmpDT = getData(data, 0);//{state, uID)

		string s_log;
		s_log += user_info[tmpDT.second]; // name
		if (tmpDT.first == "Enter")
		{
			s_log += "님이 들어왔습니다.";
		}
		else if (tmpDT.first == "Leave")
		{
			s_log += "님이 나갔습니다.";
		}
		else
			continue;
		answer.push_back(s_log);

		cout << s_log << endl;
	}
	return answer;
}

int main()
{
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
}