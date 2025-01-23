#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<pair<int, int>, string> students;
    for (int i = 0; i < N; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        students[make_pair(-marks, roll)] = name;
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            students[make_pair(-marks, roll)] = name;
            pair<int, int> max_key = students.begin()->first;
            string max_name = students.begin()->second;
            cout << max_name << " " << max_key.second << " " << -max_key.first << endl;
        }
        else if (command == 1)
        {
            if (students.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pair<int, int> max_key = students.begin()->first;
                string max_name = students.begin()->second;
                cout << max_name << " " << max_key.second << " " << -max_key.first << endl;
            }
        }
        else if (command == 2)
        {
            if (students.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pair<int, int> max_key = students.begin()->first;
                students.erase(max_key);
                if (students.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    max_key = students.begin()->first;
                    string max_name = students.begin()->second;
                    cout << max_name << " " << max_key.second << " " << -max_key.first << endl;
                }
            }
        }
    }

    return 0;
}
