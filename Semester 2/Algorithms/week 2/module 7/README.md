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

**Negative Cycle** শনাক্ত করার জন্য **Bellman-Ford Algorithm** অত্যন্ত কার্যকরী, কারণ এটি শুধুমাত্র সর্বনিম্ন পথ বের করে না, বরং কোনো **Negative Weight Cycle** (যে সাইকেল বারবার ঘুরে ছোটো ও ছোটো ওয়েট পেতে পারে) থাকলে সেটিও সনাক্ত করে।

### Negative Cycle শনাক্ত করার পদ্ধতি:

1. **Relaxation Step**: Bellman-Ford অ্যালগরিদমে প্রতিটি এজের উপর ভিত্তি করে মোট **V - 1** বার রিল্যাক্সেশন (Relaxation) করা হয়। এখানে V হল নোডের সংখ্যা।
2. **Negative Cycle Detection**: V - 1 বার রিল্যাক্সেশনের পরে যদি আবারও কোনো নোডের ওয়েট কমে যায়, তাহলে গ্রাফে **Negative Cycle** আছে বলে ধরে নেওয়া হয়।

### কোড উদাহরণ (C++):

```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
    int u, v, weight;
};

bool detectNegativeCycle(int V, int E, vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[0] = 0; // Assuming source is 0

    // Step 1: Relax all edges V-1 times
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

    // Step 2: Check for negative-weight cycles
    for (int j = 0; j < E; ++j) {
        int u = edges[j].u;
        int v = edges[j].v;
        int weight = edges[j].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            // If we can still relax an edge, it means there is a negative cycle
            return true;
        }
    }

    return false;
}

int main() {
    int V = 5;  // Number of vertices
    int E = 8;  // Number of edges
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    if (detectNegativeCycle(V, E, edges)) {
        cout << "Graph contains a negative-weight cycle" << endl;
    } else {
        cout << "No negative-weight cycle found" << endl;
    }

    return 0;
}
```

### ব্যাখ্যা:

1. **Relaxation**: প্রথমে আমরা প্রতিটি এজকে **V - 1** বার রিল্যাক্স করি (যা মিনিমাম ওয়েট আপডেট করার কাজ করে)।
2. **Negative Cycle Detection**: সব এজের উপর দিয়ে আবার যাচাই করা হয় যদি কোনো নোডের ওয়েট এখনও কমে যায়, তাহলে এটি বোঝা যায় যে গ্রাফে একটি **Negative Weight Cycle** রয়েছে।
3. **Output**: যদি নেগেটিভ সাইকেল থাকে, আমরা `"Graph contains a negative-weight cycle"` মেসেজ প্রিন্ট করি, অন্যথায় `"No negative-weight cycle found"` মেসেজ প্রিন্ট হয়।

এটি কার্যকরীভাবে নেগেটিভ ওয়েট সাইকেল শনাক্ত করতে সক্ষম।

## Floyd Warshall Algorithm

**Floyd-Warshall Algorithm** হলো একটি **dynamic programming** ভিত্তিক অ্যালগরিদম যা প্রতিটি জোড়া নোডের মধ্যে সর্বনিম্ন ওজনের পথ (shortest path) খুঁজে বের করতে ব্যবহৃত হয়। এটি সাধারণত **all-pairs shortest path algorithm** নামে পরিচিত এবং **directed** বা **undirected** গ্রাফ উভয়ের ক্ষেত্রেই কাজ করতে পারে।

### Floyd-Warshall Algorithm-এর প্রধান বৈশিষ্ট্য:

1. **Multiple Source Shortest Path**: এটি একটি গ্রাফের প্রতিটি জোড়া নোডের জন্য সর্বনিম্ন পথ নির্ণয় করে।
2. **Negative Weight Edges**: এটি নেগেটিভ ওয়েটের এজ সমর্থন করে তবে নেগেটিভ সাইকেল থাকলে সঠিক ফলাফল দেবে না।
3. **Time Complexity**: O(V³), যেখানে V হল নোডের সংখ্যা।

### কাজের ধাপসমূহ:

1. গ্রাফের সব নোডের জন্য একটি **distance matrix** তৈরি করা হয়, যেখানে প্রতিটি নোডের মধ্যবর্তী দূরত্ব সংরক্ষণ করা হয়।
2. প্রতিটি নোডকে একটি ইন্টারমিডিয়েট নোড হিসেবে ধরে নিয়ে, নোডগুলোর মধ্যবর্তী পথগুলোর দূরত্ব আপডেট করা হয়।
3. প্রতিটি নোডের জন্য আপডেটেড দূরত্ব ম্যাট্রিক্স চূড়ান্ত আকারে তৈরি করা হয়, যা সর্বনিম্ন পথের প্রতিনিধিত্ব করে।

### উদাহরণ কোড (C++):

```cpp
#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000  // Representing infinity

void floydWarshall(int V, vector<vector<int>>& dist) {
    // dist[i][j] will be the shortest distance from vertex i to vertex j

    // Applying Floyd-Warshall Algorithm
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distance matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    int V = 4;  // Number of vertices

    // Initializing the distance matrix
    vector<vector<int>> dist = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };

    // Running Floyd-Warshall Algorithm
    floydWarshall(V, dist);

    return 0;
}
```

### ব্যাখ্যা:

1. **Initial Distance Matrix**: গ্রাফের প্রতিটি নোড থেকে অন্যান্য নোডের সরাসরি দূরত্ব `dist[][]` ম্যাট্রিক্সে সংরক্ষণ করা হয়। যদি দুই নোডের মধ্যে কোনো সংযোগ না থাকে, তাহলে সেটি `INF` (infinity) দ্বারা প্রকাশ করা হয়।
2. **Dynamic Programming Approach**: প্রতিটি নোডকে **ইন্টারমিডিয়েট নোড** হিসেবে ধরে নিয়ে, আমরা অন্য দুই নোডের মধ্যে সর্বনিম্ন দূরত্ব আপডেট করি।
3. **Output**: ম্যাট্রিক্সের প্রতিটি এন্ট্রি `dist[i][j]` তে **i** থেকে **j** পর্যন্ত সর্বনিম্ন দূরত্ব পাওয়া যায়। যদি কোনও নোডে যাওয়া সম্ভব না হয়, তবে `INF` প্রিন্ট হয়।

### উপসংহার:

Floyd-Warshall অ্যালগরিদম একটি সহজ কিন্তু শক্তিশালী অ্যালগরিদম যা প্রতিটি নোডের মধ্যে সবচেয়ে কম পথ খুঁজে বের করতে সাহায্য করে।
