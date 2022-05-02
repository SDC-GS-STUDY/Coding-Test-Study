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
1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
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
        if ((id[i] >= 'a' && id[i] <= 'z') // 소문자
         || (id[i] >= '0' && id[i] <= '9') // 숫자
         ||  id[i] == '-'                  // 빼기
         ||  id[i] == '_'                  // 밑줄
         ||  id[i] == '.')                 // 마침표
        {         
            i++;
        }
        else
        {
            id.erase(id.begin() + i);
        }
        
    }
    // return id; // ,,,,,,,,,연속으로하면 반만 사라짐,, --> 인덱스가 넘어가는것을 erase가 아닐 때만
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
            i++; // erase할 때도 인덱스가 넘어가면 하나씩 누락된다
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

        // 단계별로 내려가는거면 안해도 되는건데.. 이게 머 걍 모든 조건이 맞아야되는건가봄 단계 순서에 상관없이
        // 그래서 넣어준 4단계 예외처리
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

