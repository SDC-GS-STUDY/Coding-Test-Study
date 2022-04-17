#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string answer;
    string list;

    cin >> answer;
    list.push_back(answer[0]);

    for (int i = 1; i < answer.length(); i++)
    {
        bool tmp = false;

        if (answer[i] == '-') continue;

        for (auto it : list)
        {
            if (answer[i] == it)
            {
                answer[i] = '-';
                tmp = true;
            }
        }

        if (!tmp)
            list.push_back(answer[i]);
    }


    for (auto it : answer)
    {
        if (it == '-')
        {
            continue;
        }

        cout << it;
    }

    return 0;
}
