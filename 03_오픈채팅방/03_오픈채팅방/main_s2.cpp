#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;
//2���� �õ�: STL map�� ����ؼ� �絵��!!

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

	//User ID�� ���� info log data�� map�� �����Ѵ�.
	for (auto data : record)
	{
		if (user_info.empty())
		{
			user_info.insert(getData(data, 1)); //map�� ����ִٸ� insert �Ѵ�.
			continue;
		}
		// ���� : empty check �� �� �ʿ��Ѱ�?
		
		if (user_info.find(getData(data,1).first) != user_info.end()) //info�� �̹� ����� �������
		{
			//����� �ִٸ� Leave�� Change�� ��찡 �ִ�.
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
		else //�������� ������ ������ ��� �ۿ� ����.
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
			s_log += "���� ���Խ��ϴ�.";
		}
		else if (tmpDT.first == "Leave")
		{
			s_log += "���� �������ϴ�.";
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