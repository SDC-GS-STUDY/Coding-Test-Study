#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {


    //1�ܰ� new_id�� ��� �빮�ڸ� �����Ǵ� �ҹ��ڷ� ġȯ�մϴ�.
    for (int i = 0; i < new_id.length(); i++) //�ű� ������ �Է��� ���̵� ���� ���ؼ� ��ü ������
    {
        new_id[i] = tolower(new_id[i]); //tolower �Լ� -> �ҹ��ڷ� toupper -> �빮�ڷ�
    }

    //2�ܰ� new_id���� ���ĺ� �ҹ���, ����, ����(-), ����(_), ��ħǥ(.)�� ������ ��� ���ڸ� �����մϴ�.
    for (int i = 0; i < new_id.length(); i++)
    {
        if (
            (new_id[i] >= 'a' && new_id[i] <= 'z') || //�ҹ���
            (new_id[i] >= '0' && new_id[i] <= '9') || //����
            new_id[i] == '-' || //����
            new_id[i] == '_' || //����
            new_id[i] == '.' //��ħǥ
            )
            continue;
        new_id.erase(new_id.begin() + i);
        //v.erase(v.begin() + i) ���� v�� i��° �ε����� �ִ� ���� ���� �ϰ� ���� �� erase�Լ� ���
        i--; //���� ���� ���� 
    }

    //3�ܰ� new_id���� ��ħǥ(.)�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ��ħǥ(.)�� ġȯ�մϴ�.

    for (int i = 0; i < new_id.length(); i++)
    {

    }

    //4�ܰ� new_id���� ��ħǥ(.)�� ó���̳� ���� ��ġ�Ѵٸ� �����մϴ�.
    if (new_id.front() == '.')
    {
        new_id.erase(new_id.begin()); //ó��
    }

    if (new_id.back() == '.')
    {
        new_id.erase(new_id.end() - 1); //��
    }


    // 5�ܰ� : �� ���ڿ� -> "a" ����
    if (new_id.length() == 0)
    {
        new_id = "a";
    }

    // 6�ܰ� : ���ڿ� ���� �ִ� 15��, �� ��ħǥ ����


    // 7�ܰ�  new_id�� ���̰� 2�� ���϶��, new_id�� ������ ���ڸ� new_id�� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���Դϴ�.

    while (new_id.length() < 3) {
        /*new_id += new_id[new_id.length() - 1];*/

        new_id = new_id[new_id.length() - 1] + new_id;


        return new_id;

    }