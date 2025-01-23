// #include <bits/stdc++.h>
// using namespace std;
// bool canReachN(int N)
// {
//     if (N == 1)
//         return true;
//     queue<int> q;
//     unordered_set<int> visited;
//     q.push(1);
//     visited.insert(1);
//     while (!q.empty())
//     {
//         int current = q.front();
//         q.pop();
//         int nextAdd = current + 3;
//         int nextMultiply = current * 2;
//         if (nextAdd == N || nextMultiply == N)
//         {
//             return true;
//         }
//         if (nextAdd <= N && visited.find(nextAdd) == visited.end())
//         {
//             q.push(nextAdd);
//             visited.insert(nextAdd);
//         }

//         if (nextMultiply <= N && visited.find(nextMultiply) == visited.end())
//         {
//             q.push(nextMultiply);
//             visited.insert(nextMultiply);
//         }
//     }
//     return false;
// }
// int main()
// {
//     int T;
//     cin >> T;

//     while (T--)
//     {
//         int N;
//         cin >> N;
//         if (canReachN(N))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }
//     return 0;
// }

// #include <bits/stdc++.h>
// using namespace std;
// bool canReachOne(int N)
// {
//     while (N > 1)
//     {
//         if (N % 2 == 0)
//         {
//             N /= 2;
//         }
//         else if (N % 3 == 0)
//         {
//             N -= 3;
//         }
//         else
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     int T;
//     cin >> T;

//     while (T--)
//     {
//         int N;
//         cin >> N;
//         if (canReachOne(N))
//         {
//             cout << "YES" << endl;
//         }
//         else
//         {
//             cout << "NO" << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

bool canReachN(int N)
{
    if (N == 1)
        return true;
    queue<int> q;
    bool visited[100001] = {false};
    q.push(1);
    visited[1] = true;
    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        int nextAdd = current + 3;
        int nextMultiply = current * 2;

        if (nextAdd == N || nextMultiply == N)
        {
            return true;
        }

        if (nextAdd <= N && !visited[nextAdd])
        {
            q.push(nextAdd);
            visited[nextAdd] = true;
        }

        if (nextMultiply <= N && !visited[nextMultiply])
        {
            q.push(nextMultiply);
            visited[nextMultiply] = true;
        }
    }

    return false;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        if (canReachN(N))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
