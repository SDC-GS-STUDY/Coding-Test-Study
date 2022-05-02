#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //1�ܰ�  new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
   
    for (int i = 0; i < new_id.size(); i++)
    {
        char word = new_id[i];
        new_id [i] = tolower(word);
    }
    cout << new_id << endl;
    //2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
    for (int i = 0; i < new_id.size(); i++)
    {
        char word = new_id[i];
        if ((80 <= word && word <= 89) || (97 <= word && word <= 122)) answer.push_back(word); //�ҹ���Ȯ��
        else if (word == '-' || word == '.' || word == '_') answer.push_back(word);
        else if (0+'0' <= word && word <= 9+'0') answer.push_back(word);
    }
    cout << answer << endl;

    new_id = answer;
    answer.clear();
    //3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
    int cnt = 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] != '.')
        {
            cnt = 0;
            answer.push_back(new_id[i]);
        }
        else
        {
            if (cnt == 0)
            {
                answer.push_back(new_id[i]);
                cnt++;
            }
            else
                cnt++;
        }

    }
    new_id = answer;
    cout << answer << endl;

    answer.clear();
    //4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((i == 0 || i == new_id.size() - 1) && new_id[i] == '.') continue;
        answer.push_back(new_id[i]);
    }
    new_id = answer;
    cout << answer << endl;

    //5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
    answer.clear();
    if (new_id == "") answer.push_back('a');
    new_id = answer;
    cout << answer << endl;


    //6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
    //���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
    answer.clear();
    if(new_id.size() >= 16)
    {
        for (int i = 0; i < 15; i++)
        {
            answer.push_back(new_id[i]);
        }
        if (answer.back() == '.') answer.pop_back();
        new_id = answer;
    }
    else if (new_id.size() <= 2)//7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
    {
        char last = new_id.back();
        while(new_id.size() < 3)
        {
            new_id.push_back(last);
        }
    }

    cout << new_id << endl;
    return new_id;
}

int main()
{
    solution(".AAb1.....234b-_+`.");
    //solution(".+`.");
    //solution("");
}