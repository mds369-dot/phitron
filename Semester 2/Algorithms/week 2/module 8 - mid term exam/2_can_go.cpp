// #include <bits/stdc++.h>
// using namespace std;

// const long long INF = 1e18;
// const int N = 1005;
// vector<pair<int, long long>> adj[N];
// vector<long long> dist(N, INF);
// void dijkstra(int source, int n)
// {
//     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

//     dist[source] = 0;
//     pq.push({0, source});

//     while (!pq.empty())
//     {
//         pair<long long, int> p = pq.top();
//         long long d = p.first;
//         int u = p.second;
//         pq.pop();

//         if (d > dist[u])
//             continue;

//         for (auto &edge : adj[u])
//         {
//             int v = edge.first;
//             long long w = edge.second;
//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 pq.push({dist[v], v});
//             }
//         }
//     }
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
//         adj[a].push_back({b, w});
//     }

//     int source;
//     cin >> source;
//     dijkstra(source, n);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int dest;
//         long long maxCost;
//         cin >> dest >> maxCost;

//         if (dist[dest] <= maxCost)
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

// const long long INF = 1e18;
// const int N = 1005;
// vector<pair<int, long long>> adj[N];
// vector<long long> dist(N, INF);
// vector<bool> visited(N, false);
// void bfs_dijkstra(int source, int n)
// {
//     queue<int> q;

//     dist[source] = 0;
//     q.push(source);

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         if (visited[u])
//             continue;
//         visited[u] = true;

//         for (auto &edge : adj[u])
//         {
//             int v = edge.first;
//             long long w = edge.second;
//             if (dist[u] + w < dist[v])
//             {
//                 dist[v] = dist[u] + w;
//                 q.push(v);
//             }
//         }
//     }
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
//         adj[a].push_back({b, w});
//     }

//     int source;
//     cin >> source;
//     bfs_dijkstra(source, n);

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int dest;
//         long long maxCost;
//         cin >> dest >> maxCost;

//         if (dist[dest] <= maxCost)
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

const long long INF = 1e18;
const int N = 1005;
vector<tuple<int, int, long long>> edges;
vector<long long> dist(N, INF);
void bellman_ford(int source, int n)
{
    dist[source] = 0;

    // Relax edges up to (n-1) times
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto [u, v, w] : edges)
        {
            if (dist[u] < INF && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
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

    bellman_ford(source, n);

    int t;
    cin >> t;

    while (t--)
    {
        int dest;
        long long maxCost;
        cin >> dest >> maxCost;

        if (dist[dest] <= maxCost)
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
