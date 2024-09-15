// // #include <bits/stdc++.h>
// // using namespace std;

// // const int INF = 1e9;

// // int main()
// // {
// //     int N, E;
// //     cin >> N >> E;

// //     vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
// //     for (int i = 1; i <= N; ++i)
// //     {
// //         dist[i][i] = 0;
// //     }
// //     for (int i = 0; i < E; ++i)
// //     {
// //         int A, B, W;
// //         cin >> A >> B >> W;
// //         dist[A][B] = min(dist[A][B], W);
// //     }
// //     for (int k = 1; k <= N; ++k)
// //     {
// //         for (int i = 1; i <= N; ++i)
// //         {
// //             for (int j = 1; j <= N; ++j)
// //             {
// //                 if (dist[i][k] < INF && dist[k][j] < INF)
// //                 {
// //                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
// //                 }
// //             }
// //         }
// //     }
// //     int Q;
// //     cin >> Q;
// //     while (Q--)
// //     {
// //         int X, Y;
// //         cin >> X >> Y;
// //         if (dist[X][Y] == INF)
// //         {
// //             cout << -1 << endl;
// //         }
// //         else
// //         {
// //             cout << dist[X][Y] << endl;
// //         }
// //     }

// //     return 0;
// // }

// #include <bits/stdc++.h>
// using namespace std;

// const int INF = INT_MAX;

// int main()
// {
//     int N, E;
//     cin >> N >> E;

//     vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));
//     for (int i = 1; i <= N; ++i)
//     {
//         dist[i][i] = 0;
//     }
//     for (int i = 0; i < E; ++i)
//     {
//         int A, B, W;
//         cin >> A >> B >> W;
//         dist[A][B] = min(dist[A][B], W);
//     }

//     for (int k = 1; k <= N; ++k)
//     {
//         for (int i = 1; i <= N; ++i)
//         {
//             for (int j = 1; j <= N; ++j)
//             {
//                 if (dist[i][k] < INF && dist[k][j] < INF)
//                 {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
//     int Q;
//     cin >> Q;
//     while (Q--)
//     {
//         int X, Y;
//         cin >> X >> Y;
//         if (dist[X][Y] == INF)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << dist[X][Y] << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 101;
const int INF = 1e9;

vector<pair<int, int>> adj[MAXN];

int dijkstra(int source, int destination)
{
    vector<int> dist(MAXN, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto &v : adj[u])
        {
            int weight = v.second;
            if (dist[u] + weight >= dist[v.first])
            {
                continue; // Skip to next neighbor if current is not better
            }
            dist[v.first] = dist[u] + weight;
            pq.push({dist[v.first], v.first});
        }
    }

    return dist[destination] == INF ? -1 : dist[destination];
}

int main()
{
    int N, E, Q;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
    }

    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        int X, Y;
        cin >> X >> Y;
        int minCost = dijkstra(X, Y);
        cout << minCost << endl;
    }

    return 0;
}