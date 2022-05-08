#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {


    //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    for (int i = 0; i < new_id.length(); i++) //신규 유저가 입력한 아이디 길이 구해서 전체 돌리기
    {
        new_id[i] = tolower(new_id[i]); //tolower 함수 -> 소문자로 toupper -> 대문자로
    }

    //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    for (int i = 0; i < new_id.length(); i++)
    {
        if (
            (new_id[i] >= 'a' && new_id[i] <= 'z') || //소문자
            (new_id[i] >= '0' && new_id[i] <= '9') || //숫자
            new_id[i] == '-' || //빼기
            new_id[i] == '_' || //밑줄
            new_id[i] == '.' //마침표
            )
            continue;
        new_id.erase(new_id.begin() + i);
        //v.erase(v.begin() + i) 벡터 v의 i번째 인덱스에 있는 원소 삭제 하고 싶을 때 erase함수 사용
        i--; //지운 길이 삭제 
    }

    //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.

    for (int i = 0; i < new_id.length(); i++)
    {

    }

    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (new_id.front() == '.')
    {
        new_id.erase(new_id.begin()); //처음
    }

    if (new_id.back() == '.')
    {
        new_id.erase(new_id.end() - 1); //끝
    }


    // 5단계 : 빈 문자열 -> "a" 대입
    if (new_id.length() == 0)
    {
        new_id = "a";
    }

    // 6단계 : 문자열 길이 최대 15자, 끝 마침표 제거


    // 7단계  new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.

    while (new_id.length() < 3) {
        /*new_id += new_id[new_id.length() - 1];*/

        new_id = new_id[new_id.length() - 1] + new_id;


        return new_id;

    }