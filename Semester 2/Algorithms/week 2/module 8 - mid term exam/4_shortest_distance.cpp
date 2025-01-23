#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;

vector<int> dijkstra(int source, int N, const vector<vector<pair<int, int>>> &adj)
{
    vector<int> dist(N + 1, INF);
    dist[source] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty())
    {
        int currDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (currDist > dist[u])
            continue;
        for (auto &neighbor : adj[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (dist[u] + weight < dist[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main()
{
    int N, E;
    cin >> N >> E;
    vector<vector<pair<int, int>>> adj(N + 1);
    unordered_map<int, unordered_map<int, int>> edge_map;

    // Reading the edges
    for (int i = 0; i < E; ++i)
    {
        int A, B, W;
        cin >> A >> B >> W;
        if (edge_map[A].count(B))
        {
            edge_map[A][B] = min(edge_map[A][B], W);
        }
        else
        {
            edge_map[A][B] = W;
        }
    }
    for (auto &u : edge_map)
    {
        int from = u.first;
        for (auto &v : u.second)
        {
            int to = v.first;
            int weight = v.second;
            adj[from].push_back({to, weight});
        }
    }

    int Q;
    cin >> Q;

    vector<pair<int, int>> queries(Q);
    vector<vector<int>> distances(N + 1);
    for (int i = 0; i < Q; ++i)
    {
        int X, Y;
        cin >> X >> Y;
        queries[i] = {X, Y};
        if (distances[X].empty())
        {
            distances[X] = dijkstra(X, N, adj);
        }
    }
    for (int i = 0; i < Q; ++i)
    {
        int X = queries[i].first;
        int Y = queries[i].second;
        int result = distances[X][Y];
        if (result == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}
