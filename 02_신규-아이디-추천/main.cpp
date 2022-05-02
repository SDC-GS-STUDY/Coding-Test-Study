#include <string>
#include <vector>
#include <stack>
#include <utility>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";

    //1단계  new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
   
    for (int i = 0; i < new_id.size(); i++)
    {
        char word = new_id[i];
        new_id [i] = tolower(word);
    }
    cout << new_id << endl;
    //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    for (int i = 0; i < new_id.size(); i++)
    {
        char word = new_id[i];
        if ((80 <= word && word <= 89) || (97 <= word && word <= 122)) answer.push_back(word); //소문자확인
        else if (word == '-' || word == '.' || word == '_') answer.push_back(word);
        else if (0+'0' <= word && word <= 9+'0') answer.push_back(word);
    }
    cout << answer << endl;

    new_id = answer;
    answer.clear();
    //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
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
    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    for (int i = 0; i < new_id.size(); i++)
    {
        if ((i == 0 || i == new_id.size() - 1) && new_id[i] == '.') continue;
        answer.push_back(new_id[i]);
    }
    new_id = answer;
    cout << answer << endl;

    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    answer.clear();
    if (new_id == "") answer.push_back('a');
    new_id = answer;
    cout << answer << endl;


    //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
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
    else if (new_id.size() <= 2)//7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
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