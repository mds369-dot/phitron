#include <bits/stdc++.h>
using namespace std;
// class Pair
// {
// public:
//     int first, second;
//     void make_pair(int a, int b)
//     {
//         first = a;
//         second = b;
//     }
// };

int main()
{
    // Pair p;
    // p.first = 10;
    // p.second = 20;
    // cout << p.first << " " << p.second << endl;

    // pair<int, int> p;
    pair<string, int> p;
    p = make_pair("shagor", 20);
    cout << p.first << " " << p.second << endl;
    return 0;
}