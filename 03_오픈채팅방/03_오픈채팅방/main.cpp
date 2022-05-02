#include <iostream>
#include <utility>
#include <vector>
using namespace std;
//ds
void DebugLog(vector<pair<int, pair<string, string>>> log_table)
{
	cout << "===========Update===========" << endl;
	for (auto log : log_table)
	{
		std::cout << "State:" << log.first << "    ID:" << log.second.first << "    Name:" << log.second.second << endl;
	}

	return;
}

vector<string> solution(vector<string> record) {
	vector<string> answer;

	vector<pair<int, pair<string, string>>> log_table;
	int table_idx = 0;

	int idx = 0;
	int bnk_cnt = 0;

	vector<pair<string, string>> m_joinLog; //ä�ù濡 ������ �̷� �Ǵ� ���� �ִ� member
	//Data pharsing and Update
	for (auto rec : record)  //record -> sentence
	{
		pair<string, string> user_info;
		int state = 0; // Enter = 0; Leave = 1, Chage = 2;
		for (int i = 0; i < rec.size(); i++)// sentence-> char
		{
			if (rec[i] != ' ') continue;
			switch (bnk_cnt)
			{
			case 0: //Enter,Exit
				if (rec.substr(idx, i) == "Enter") state = 0;
				else if (rec.substr(idx, i) == "Leave")
				{
					state = 1;
					user_info.first = rec.substr(idx+i+1, rec.size() - idx+1);
					user_info.second = "none";
				}
				else if (rec.substr(idx, i) == "Change") state = 2;
				idx = i + 1;//���� ���� index
				break;
			case 1:
				user_info.first = rec.substr(idx, i - idx);
				user_info.second = "none";
				
				idx = i + 1;//���� ���� index
				user_info.second = rec.substr(idx, rec.size()- idx);
				break;
			}
			bnk_cnt++;
		}
		log_table.push_back({ state, {user_info} });

		//debug.Data Log
		std::cout << "State:" << state << "    ID:" << user_info.first << "    Name:" << user_info.second << endl;

		//Upate Data : �̸��� �ٲ�� ���� ��� �̸��� �ٲ��. 1. ������ �̸� �ٲ�� ��� 2. ���ο��� �̸��� �ٲ� ���
     	//1. Check new member ID is it prev member. 
	    // 1-1. Check is name changed
		if (state == 0)
		{
			//���� ������� �ƴ��� �˻�
			bool isOrigin = false;		
			for (auto member : m_joinLog)
			{
				if (member.first == user_info.first)
				{
					isOrigin = true;
					break;
				}
			}

			//ä�ù濡 ���� ���� ����� ���� ����� ���
			if (isOrigin)
			{
				for (auto& info : log_table)
				{
					if (info.second.first == user_info.first && info.second.second != user_info.second)
					{
						info.second.second = user_info.second; //change to new name
						DebugLog(log_table);
					}
				}
			}
			else
			{
				m_joinLog.push_back(user_info);
			}

		}
		else if (state == 2)  //2. Change the name in chat room.  -> just change all name
		{
			for (auto& info : log_table)
			{
				if (info.second.first == user_info.first)
				{
					info.second.second = user_info.second; //change to new name
					DebugLog(log_table);
				}
			}
		}



		idx = 0;
		bnk_cnt = 0;
		state = 0;

		table_idx++;
	}

	cout << "RESULT LOG" << endl;
	//Printing Result
	for (auto log : log_table)
	{
		int state = log.first;
		string s_log;
		s_log += log.second.second; // 000
		s_log += "���� ";

		if (state == 0)
		{
			s_log += "���Խ��ϴ�.";
		}
		else if (state == 1)
		{
			s_log += "�������ϴ�.";
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