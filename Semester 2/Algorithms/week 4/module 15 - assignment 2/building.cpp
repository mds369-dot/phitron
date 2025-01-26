// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int par[N];
// int grp_size[N];
// void dsu_inz(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         par[i] = -1;
//         grp_size[i] = 1;
//     }
// }
// int dsu_find(int node)
// {
//     if (par[node] == -1)
//     {
//         return node;
//     }
//     return par[node] = dsu_find(par[node]);
// }
// bool dsu_U_by_size(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA == leaderB)
//     {
//         return false;
//     }
//     if (grp_size[leaderA] > grp_size[leaderB])
//     {
//         par[leaderB] = leaderA;
//         grp_size[leaderA] += grp_size[leaderB];
//     }
//     else
//     {
//         par[leaderA] = leaderB;
//         grp_size[leaderB] += grp_size[leaderA];
//     }
//     return true;
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<pair<int, pair<int, int>>> edges;
//     for (int i = 0; i < e; i++)
//     {
//         int a, b, c;
//         cin >> a >> b >> c;
//         edges.push_back({c, {a, b}});
//     }
//     sort(edges.begin(), edges.end());
//     dsu_inz(n);

//     int totalCosts = 0;
//     int edgesUsed = 0;
//     for (auto &edge : edges)
//     {
//         int c = edge.first;
//         int a = edge.second.first;
//         int b = edge.second.second;

//         if (dsu_U_by_size(a, b))
//         {
//             totalCosts += c;
//             edgesUsed++;
//         }
//     }
//     if (edgesUsed == n - 1)
//     {
//         cout << totalCosts << endl;
//     }
//     else
//     {
//         cout << -1 << endl;
//     }

//     return 0;
// }
// #include <bits/stdc++.h>
// using namespace std;
// struct Edge
// {
//     int u, v, w;
// };
// int find(int u, vector<int> &parent)
// {
//     if (parent[u] == u)
//         return u;
//     return parent[u] = find(parent[u], parent);
// }
// bool unite(int u, int v, vector<int> &parent, vector<int> &rank)
// {
//     u = find(u, parent);
//     v = find(v, parent);
//     if (u == v)
//         return false;

//     if (rank[u] < rank[v])
//         swap(u, v);
//     parent[v] = u;
//     if (rank[u] == rank[v])
//         rank[u]++;
//     return true;
// }
// int kruskal(int n, vector<Edge> &edges)
// {
//     sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
//          { return a.w < b.w; });
//     vector<int> parent(n + 1), rank(n + 1, 0);
//     for (int i = 1; i <= n; i++)
//         parent[i] = i;

//     int mst_cost = 0;
//     int edges_used = 0;
//     for (auto &edge : edges)
//     {
//         if (unite(edge.u, edge.v, parent, rank))
//         {
//             mst_cost += edge.w;
//             edges_used++;
//             if (edges_used == n - 1)
//                 break;
//         }
//     }
//     if (edges_used != n - 1)
//         return -1;
//     return mst_cost;
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;

//     vector<Edge> edges(e);

//     for (int i = 0; i < e; i++)
//     {
//         cin >> edges[i].u >> edges[i].v >> edges[i].w;
//     }
//     int result = kruskal(n, edges);
//     cout << result << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN];
bool visited[MAXN];

int primMST(int N)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    int total_cost = 0;
    int edges_used = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;
        total_cost += cost;
        edges_used++;

        for (auto next : adj[node])
        {
            int next_node = next.first;
            int next_cost = next.second;
            if (!visited[next_node])
            {
                pq.push({next_cost, next_node});
            }
        }
    }

    if (edges_used == N)
    {
        return total_cost;
    }
    else
    {
        return -1;
    }
}

int main()
{
    int N, E;
    cin >> N >> E;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int result = primMST(N);
    cout << result << endl;

    return 0;
}
