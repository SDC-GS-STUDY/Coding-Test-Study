#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    // step 1
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]); // 소문자를 대문자로
        }
    }

    // step 2
    for (int i = 0; i < new_id.length();) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] >= 'a' && new_id[i] <= 'z')) {
            i++; // shift 현상 일어나서 아예 for문에서 i++ 없애고 해야 함 안 그러면 자꾸 뒤로 밀려남. 그리고 문자열이라는 거 잊지 말기!
            continue;
        }
        new_id.erase(new_id.begin() + i); // 이렇게 안 하니까 abort() 오류 떠서 계속 찾아봄 이렇게 하는 게 맞음
    }

    // step 3
    for (int i = 1; i < new_id.length();) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i); // i = i+1 로 했더니 진짜 자꾸 뒤로 밀리고 엉뚱한 게 사라져서 다시 해봄..1부터 시작해야 깔끔하게 됨
            continue;
        }
        else
            i++;
    }

    // step 4
    if(new_id.empty() == false) // 이거 없으면 "=.=" 이거 망할 거 오류 뜸
        if (new_id.front() == '.') new_id.erase(new_id.begin());
    if(new_id.empty() == false)
        if (new_id.back() == '.') new_id.erase(new_id.end() - 1);

    // step 5
    if (new_id.empty()) {
        new_id = 'a';
    }

    // step 6
    if (new_id.length() >= 16) {
        while (new_id.length() != 15) {
            new_id.erase(new_id.begin() + 15);
        }
    }
    if (new_id.back() == '.')
        new_id.erase(new_id.end() - 1);

    // step 7
    if (new_id.length() <= 2) {
        while (new_id.length() != 3) {
            new_id += new_id.back();
        }
    }

    return new_id;
}

int main() {
    cout << solution("...!@BaT#*..y.abcdefghijklm") << endl;
    cout << solution("z-+.^.") << endl;
    cout << solution("=.=") << endl;
    cout << solution("123_.def") << endl;
    cout << solution("abcdefghijklmn.p") << endl;

}