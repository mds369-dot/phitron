// 1 Code

// #include <bits/stdc++.h>
// using namespace std;

// class Student
// {
// public:
//     string name;
//     int roll;
//     Student(string name, int roll)
//     {
//         this->name = name;
//         this->roll = roll;
//     }
// };
// class cmp
// {
// public:
//     bool operator()(Student a, Student b)
//     {

//         if (a.name != b.name)
//             return a.name > b.name;
//         return a.roll < b.roll;
//     }
// };

// 2 Code

// int main()
// {
//     int n;
//     cin >> n;

//     priority_queue<Student, vector<Student>, cmp> pq;

//     for (int i = 0; i < n; i++)
//     {
//         string name;
//         int roll;
//         cin >> name >> roll;
//         Student obj(name, roll);
//         pq.push(obj);
//     }

//     while (!pq.empty())
//     {
//         cout << pq.top().name << " " << pq.top().roll << endl;
//         pq.pop();
//     }

//     return 0;
// }

// 3 Code

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;

//     map<string, int> studentMap;

//     for (int i = 0; i < n; i++)
//     {
//         string name;
//         int roll;
//         cin >> name >> roll;
//         studentMap.insert(make_pair(name, roll));
//     }

//     for (auto it = studentMap.begin(); it != studentMap.end(); ++it)
//     {
//         cout << it->first << " " << it->second << endl;
//     }

//     return 0;
// }

// 4 Code

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n;
//     cin >> n;
//     map<string, vector<int>> studentMap;

//     for (int i = 0; i < n; i++)
//     {
//         string name;
//         int roll;
//         cin >> name >> roll;
//         studentMap[name].push_back(roll);
//     }
//     for (auto &entry : studentMap)
//     {
//         sort(entry.second.rbegin(), entry.second.rend());
//     }
//     for (auto &entry : studentMap)
//     {
//         for (int roll : entry.second)
//         {
//             cout << entry.first << " " << roll << endl;
//         }
//     }

//     return 0;
// }

// 5 Code

#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    int roll;

    Student(string name, int roll)
    {
        this->name = name;
        this->roll = roll;
    }
};

int main()
{
    int n;
    cin >> n;

    map<string, vector<int>> studentMap;

    for (int i = 0; i < n; i++)
    {
        string name;
        int roll;
        cin >> name >> roll;
        studentMap[name].push_back(roll);
    }

    vector<Student> sortedStudents;

    for (auto &entry : studentMap)
    {
        sort(entry.second.begin(), entry.second.end(), greater<int>());
        for (int roll : entry.second)
        {
            sortedStudents.push_back(Student(entry.first, roll));
        }
    }

    for (Student student : sortedStudents)
    {
        cout << student.name << " " << student.roll << endl;
    }

    return 0;
}
