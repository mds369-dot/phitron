# Module 7

## Bellman Ford Algorithm

- Single source shortage path বের করার জন্য।
- O ----- 1 ------ 2 । ০ থেকে ১ এ যাওয়া যায় ১ থেকে ২ এ যাওয়া যায় এবং ২ থেকে আবার ০ তে যাওয়া যায়।
- Negative cycle এ ব্যবহার হয়।
  **Bellman-Ford Algorithm** হলো একটি গ্রাফ অ্যালগরিদম যা ডিরেক্টেড গ্রাফে (directed graph) নির্দিষ্ট একটি সোর্স ভেরটেক্স থেকে অন্য ভেরটেক্স পর্যন্ত সর্বনিম্ন ওজন (minimum weight) বা দূরত্ব বের করতে ব্যবহৃত হয়। এটি একটি **negative weight edge** সম্বলিত গ্রাফে কাজ করতে পারে, যেখানে **Dijkstra’s Algorithm** কাজ করে না।

### Bellman-Ford Algorithm-এর প্রধান বৈশিষ্ট্য:

1. **Negative Weight Cycle Detection**: যদি গ্রাফে কোন নেগেটিভ ওয়েটের সাইকেল থাকে, তবে এই অ্যালগরিদম সেটি খুঁজে বের করতে পারে।
2. **Relaxation Process**: এটি প্রতিটি এজের জন্য নির্দিষ্ট সোর্স থেকে অন্যান্য নোডের জন্য মিনিমাম ডিসটেন্স আপডেট করতে থাকে।
3. **Complexity**: এর টাইম কমপ্লেক্সিটি হল O(V \* E), যেখানে V হলো নোডের সংখ্যা এবং E হলো এজের সংখ্যা।

### কাজের ধাপসমূহ:

1. প্রথমে প্রতিটি নোডের জন্য ইনফিনিটি (∞) ওয়েট অ্যাসাইন করা হয়, শুধু সোর্স নোডের জন্য ওয়েট হয় ০।
2. এরপর প্রতিটি এজের জন্য বারবার রিল্যাক্সেশন (Relaxation) করা হয়, অর্থাৎ যদি নতুন কোনো কম দূরত্ব পাওয়া যায়, তাহলে সেটি আপডেট করা হয়।
3. এই প্রক্রিয়াটি **V - 1** বার করা হয় যেখানে V হলো নোডের সংখ্যা।
4. শেষ ধাপে আবার সব এজগুলো চেক করা হয় যদি কোনও নোডে কম ওয়েট আপডেট হয়, তার মানে গ্রাফে নেগেটিভ ওয়েট সাইকেল রয়েছে।

### উদাহরণ কোড (C++):

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

void bellmanFord(int V, int E, int src, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; ++i) {
        for (int j = 0; j < E; ++j) {
            int u = edges[j].u;
            int v = edges[j].v;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Check for negative-weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Print the shortest distances
    for (int i = 0; i < V; ++i) {
        cout << "Distance from source " << src << " to vertex " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int V = 5;  // Number of vertices
    int E = 8;  // Number of edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, 0, edges);

    return 0;
}
```

এই কোডটি ৫টি নোডের একটি গ্রাফে বেলম্যান-ফোর্ড অ্যালগরিদম প্রয়োগ করে সোর্স নোড ০ থেকে অন্যান্য নোডের সর্বনিম্ন দূরত্ব বের করবে।

## Floyd Warshall Algorithm
