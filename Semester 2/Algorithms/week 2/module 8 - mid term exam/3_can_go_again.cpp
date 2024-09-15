// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1e18;
// const int N = 1005;
// vector<tuple<int, int, long long>> edges;
// vector<long long> dist(N, INF);
// bool bellman_ford(int source, int n)
// {
//     dist[source] = 0;
//     for (int i = 1; i <= n - 1; i++)
//     {
//         for (auto [u, v, w] : edges)
//         {
//             if (dist[u] < INF && dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//             }
//         }
//     }
//     for (auto [u, v, w] : edges)
//     {
//         if (dist[u] < INF && dist[u] + w < dist[v])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     for (int i = 0; i < e; i++)
//     {
//         int a, b;
//         long long w;
//         cin >> a >> b >> w;
//         edges.push_back(make_tuple(a, b, w));
//     }

//     int source;
//     cin >> source;
//     bool noNegativeCycle = bellman_ford(source, n);
//     if (!noNegativeCycle)
//     {
//         cout << "Negative Cycle Detected" << endl;
//         return 0;
//     }

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int dest;
//         cin >> dest;

//         if (dist[dest] == INF)
//         {
//             cout << "Not Possible" << endl;
//         }
//         else
//         {
//             cout << dist[dest] << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int N = 1005;
vector<tuple<int, int, long long>> edges;
vector<long long> dist(N, INF);
bool bellman_ford(int source, int n)
{
    dist[source] = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto edge : edges)
        {
            int u = get<0>(edge);
            int v = get<1>(edge);
            long long w = get<2>(edge);
            if (dist[u] < INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    for (auto edge : edges)
    {
        int u = get<0>(edge);
        int v = get<1>(edge);
        long long w = get<2>(edge);
        if (dist[u] < INF && dist[u] + w < dist[v])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        edges.push_back(make_tuple(a, b, w));
    }

    int source;
    cin >> source;
    bool noNegativeCycle = bellman_ford(source, n);
    if (!noNegativeCycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int dest;
        cin >> dest;

        if (dist[dest] == INF)
        {
            cout << "Not Possible" << endl;
        }
        else
        {
            cout << dist[dest] << endl;
        }
    }

    return 0;
}
