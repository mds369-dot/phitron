#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int N = 1005;
vector<pair<int, long long>> adj[N];
vector<long long> dist(N, INF);
vector<bool> visited(N, false);
void bfs_dijkstra(int source, int n)
{
    queue<int> q;

    dist[source] = 0;
    q.push(source);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            long long w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push(v);
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
        adj[a].push_back({b, w});
    }

    int source;
    cin >> source;
    bfs_dijkstra(source, n);

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
