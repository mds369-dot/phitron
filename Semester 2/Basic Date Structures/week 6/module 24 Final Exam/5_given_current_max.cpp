#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<int, set<pair<int, string>>> students;
    for (int i = 0; i < N; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        students[marks].insert(make_pair(roll, name));
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
            students[marks].insert(make_pair(roll, name));
            auto it = prev(students.end());
            cout << it->second.begin()->second << " " << it->second.begin()->first << " " << it->first << endl;
        }
        else if (command == 1)
        {
            if (students.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                auto it = prev(students.end());
                cout << it->second.begin()->second << " " << it->second.begin()->first << " " << it->first << endl;
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
                auto it = prev(students.end());
                auto student_to_remove = it->second.begin();

                string name = student_to_remove->second;
                int roll = student_to_remove->first;
                int marks = it->first;
                it->second.erase(student_to_remove);
                if (it->second.empty())
                {
                    students.erase(it);
                }
                if (students.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    auto new_max = prev(students.end());
                    cout << new_max->second.begin()->second << " " << new_max->second.begin()->first << " " << new_max->first << endl;
                }
            }
        }
    }

    return 0;
}
