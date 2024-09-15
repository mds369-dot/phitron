#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX;

struct Edge
{
    int node, weight;
    Edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

vector<vector<Edge>> adj;
vector<vector<int>> dist;

void dijkstra(int src, int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> minDist(N + 1, INF);

    minDist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > minDist[u])
            continue;

        for (Edge e : adj[u])
        {
            int v = e.node;
            int weight = e.weight;
            if (minDist[u] + weight < minDist[v])
            {
                minDist[v] = minDist[u] + weight;
                pq.push({minDist[v], v});
            }
        }
    }

    dist[src] = minDist;
}

int main()
{
    int N, E;
    cin >> N >> E;

    adj.resize(N + 1);
    dist.resize(N + 1, vector<int>(N + 1, INF));

    // Reading graph input, handling multiple edges
    for (int i = 0; i < E; i++)
    {
        int A, B, W;
        cin >> A >> B >> W;

        // Add edge, keep only the smallest weight for any A -> B
        bool found = false;
        for (Edge &e : adj[A])
        {
            if (e.node == B)
            {
                if (W < e.weight)
                {
                    e.weight = W; // Update with the smaller weight
                }
                found = true;
                break;
            }
        }
        if (!found)
        {
            adj[A].push_back(Edge(B, W));
        }
    }

    // Run Dijkstra for each node
    for (int i = 1; i <= N; i++)
    {
        dijkstra(i, N);
    }

    int Q;
    cin >> Q;
    while (Q--)
    {
        int X, Y;
        cin >> X >> Y;
        int result = dist[X][Y];
        if (result == INF)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << result << endl;
        }
    }

    return 0;
}
