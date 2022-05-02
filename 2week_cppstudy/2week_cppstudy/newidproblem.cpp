#include <iostream>
#include <string>
#include <vector>

using namespace std;

char lowerAlphabat(char temp);
string phase1(string id);
string phase2(string id);
string phase3(string id);
string phase4(string id);
string phase5(string id);
string phase6(string id);
string phase7(string id);
string solution(string new_id);

int main()
{
    string playerID;

    cin >> playerID;

    cout << solution(playerID) << endl;
    
    return 0;
}

/*
1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.
4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
5�ܰ� new_id�� �� ���ڿ��̶��, new_id�� "a"�� �����մϴ�.
6�ܰ� new_id�� ���̰� 16�� �̻��̸�, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ��� ��� �����մϴ�.
     ���� ���� �� ��ħǥ(.)�� new_id�� ���� ��ġ�Ѵٸ� ���� ��ġ�� ��ħǥ(.) ���ڸ� �����մϴ�.
7�ܰ� new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.
*/

string solution(string new_id) {

    string answer = "";    

    answer = phase1(new_id);

    return answer;
}

char lowerAlphabat(char temp)
{
    switch (temp)
    {
    case 'A':
        return 'a';
        break;
    case 'B':
        return 'b';
        break;
    case 'C':
        return 'c';
        break;
    case 'D':
        return 'd';
        break;
    case 'E':
        return 'e';
        break;
    case 'F':
        return 'f';
        break;
    case 'G':
        return 'g';
        break;
    case 'H':
        return 'h';
        break;
    case 'I':
        return 'i';
        break;
    case 'J':
        return 'j';
        break;
    case 'K':
        return 'k';
        break;
    case 'L':
        return 'l';
        break;
    case 'M':
        return 'm';
        break;
    case 'N':
        return 'n';
        break;
    case 'O':
        return 'q';
        break;
    case 'P':
        return 'p';
        break;
    case 'Q':
        return 'q';
        break;
    case 'R':
        return 'r';
        break;
    case 'S':
        return 's';
        break;
    case 'T':
        return 't';
        break;
    case 'U':
        return 'u';
        break;
    case 'V':
        return 'v';
        break;
    case 'W':
        return 'w';
        break;
    case 'X':
        return 'x';
        break;
    case 'Y':
        return 'y';
        break;
    case 'Z':
        return 'z';
        break;

    default:
        return 0;
        break;
    }
}

string phase1(string id)
{
    for (int i = 0; i < id.length(); i++)
    {
        if (id[i] >= 'A' && id[i] <= 'Z')
            id[i] = lowerAlphabat(id[i]);
    }
    return phase2(id);
}

string phase2(string id)
{
    for (int i = 0; i < id.length();) //i++)
    {
        if ((id[i] >= 'a' && id[i] <= 'z') // �ҹ���
         || (id[i] >= '0' && id[i] <= '9') // ����
         ||  id[i] == '-'                  // ����
         ||  id[i] == '_'                  // ����
         ||  id[i] == '.')                 // ��ħǥ
        {         
            i++;
        }
        else
        {
            id.erase(id.begin() + i);
        }
        
    }
    // return id; // ,,,,,,,,,���������ϸ� �ݸ� �����,, --> �ε����� �Ѿ�°��� erase�� �ƴ� ����
    return phase3(id);
}

string phase3(string id)
{
    for (int i = 0; i < id.length();)// i++)
    {
        if (id[i] == '.' && id[i + 1] == '.')
        {
            id.erase(id.begin() + i);
        }
        else
            i++; // erase�� ���� �ε����� �Ѿ�� �ϳ��� �����ȴ�
    }
    //return id;
     return phase4(id);
}

string phase4(string id)
{
    if (id[0] == '.') id.erase(id.begin());
    if (!id.empty())
    {
        if (id[id.length() - 1] == '.')
        {
            id.erase(id.length() - 1);
        }
    }    

    //return id;
    return phase5(id);
}

string phase5(string id)
{
    if (id.empty()) 
        id = 'a';
    //return id;
    return phase6(id);
}

string phase6(string id)
{
    if (id.length() >= 16)
    {
        while (true)
        {
            id.erase(id.end() - 1);
            
            if (id.length() == 15) break;
        }

        // �ܰ躰�� �������°Ÿ� ���ص� �Ǵ°ǵ�.. �̰� �� �� ��� ������ �¾ƾߵǴ°ǰ��� �ܰ� ������ �������
        // �׷��� �־��� 4�ܰ� ����ó��
        if (id[id.length() - 1] == '.') 
            id.erase(id.length() - 1);
    }
    //return id;
    return phase7(id);
}

string phase7(string id)
{
    if (id.length() <= 2)
    {
        while (true)
        {
            id += id[id.length()-1];

            if (id.length() >= 3) break;
        }
    }

    return id;
}

