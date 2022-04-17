#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {

    // step 1
    for (int i = 0; i < new_id.length(); i++) {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
            new_id[i] = tolower(new_id[i]); // �ҹ��ڸ� �빮�ڷ�
        }
    }

    // step 2
    for (int i = 0; i < new_id.length();) {
        if (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.' || (new_id[i] >= '0' && new_id[i] <= '9') || (new_id[i] >= 'a' && new_id[i] <= 'z')) {
            i++; // shift ���� �Ͼ�� �ƿ� for������ i++ ���ְ� �ؾ� �� �� �׷��� �ڲ� �ڷ� �з���. �׸��� ���ڿ��̶�� �� ���� ����!
            continue;
        }
        new_id.erase(new_id.begin() + i); // �̷��� �� �ϴϱ� abort() ���� ���� ��� ã�ƺ� �̷��� �ϴ� �� ����
    }

    // step 3
    for (int i = 1; i < new_id.length();) {
        if (new_id[i] == '.' && new_id[i - 1] == '.') {
            new_id.erase(new_id.begin() + i); // i = i+1 �� �ߴ��� ��¥ �ڲ� �ڷ� �и��� ������ �� ������� �ٽ� �غ�..1���� �����ؾ� ����ϰ� ��
            continue;
        }
        else
            i++;
    }

    // step 4
    if (new_id.empty() == false) // �̰� ������ "=.=" �̰� ���� �� ���� ��
        if (new_id.front() == '.') new_id.erase(new_id.begin());
    if (new_id.empty() == false)
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