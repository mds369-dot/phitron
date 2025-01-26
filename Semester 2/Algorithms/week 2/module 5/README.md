# Module 5

## Detect Cycle in Undirected Graph

Undirected Graph-এ **Cycle Detection** বলতে এমন একটি পথ খুঁজে বের করাকে বোঝায়, যেখানে কোনো node থেকে শুরু করে কিছু edge পার হয়ে আবার সেই node-এ ফিরে আসা যায়, অর্থাৎ, গ্রাফে বন্ধ চক্র বা cycle গঠিত হয়।

Cycle detection-এর জন্য সাধারণত দু'টি পদ্ধতি ব্যবহৃত হয়:

### ১. **DFS (Depth-First Search) Algorithm**

DFS ব্যবহার করে একটি node থেকে traversal শুরু করা হয়। যদি কোনো node-এর adjacent (প্রতিবেশী) node-এ traversal করার সময় দেখা যায় যে সেই node-এ আগে traversal করা হয়েছে এবং এটি current node-এর parent না হয়, তাহলে সেখানে একটি cycle আছে বলা যায়।

#### DFS ভিত্তিক পদ্ধতি:

- প্রতিটি node-এর জন্য একটি visited array ব্যবহার করা হয়।
- প্রতিটি node-এর parent কে track করা হয়।
- যদি কোনো node পুনরায় ভিজিট করা হয় এবং সেটি parent না হয়, তবে সেটি একটি cycle নির্দেশ করে।

### ২. **BFS (Breadth-First Search) Algorithm**

BFS-ও একইভাবে কাজ করে। আমরা প্রতিটি node এবং তার parent track করি। যদি কোনো adjacent node ভিজিটেড হয় এবং সেটি parent না হয়, তাহলে এটি একটি cycle নির্দেশ করে।

### উদাহরণ:

নিচের গ্রাফে একটি cycle রয়েছে:

```
   1 ---- 2
   |      |
   |      |
   4 ---- 3
```

এখানে 1 → 2 → 3 → 4 → 1 এই পথটি একটি cycle নির্দেশ করছে।

### C++ কোড (DFS ভিত্তিক):

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isCyclicDFS(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, node, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, -1, adj, visited)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0] = {1, 3};
    adj[1] = {0, 2};
    adj[2] = {1, 3};
    adj[3] = {0, 2};

    if (hasCycle(n, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
```

এই কোডটি DFS পদ্ধতি ব্যবহার করে একটি cycle খুঁজে বের করে। `isCyclicDFS` ফাংশনটি প্রতিটি node থেকে তার প্রতিবেশীর মাধ্যমে traversal করে এবং cycle আছে কিনা তা খুঁজে বের করে।

**Directed Graph**-এ **Cycle Detection** বলতে এমন একটি পথ খুঁজে বের করা বোঝায় যেখানে কোনো node থেকে শুরু করে কিছু edge পার হয়ে আবার সেই node-এ ফিরে আসা যায়। Directed Graph-এর ক্ষেত্রে cycle detection সাধারণত **DFS (Depth-First Search)** এবং **Kahn’s Algorithm (Topological Sorting)** এর মাধ্যমে করা হয়।

### ১. **DFS (Depth-First Search) Algorithm:**

DFS পদ্ধতিতে directed graph-এ cycle আছে কিনা তা খুঁজে বের করার জন্য আমরা দুই ধরনের array ব্যবহার করি:

- **visited[]**: একটি node পূর্বে ভিজিট করা হয়েছে কিনা তা track করে।
- **recStack[] (recursion stack)**: বর্তমানে DFS recursion-এর মধ্যে থাকা node গুলো track করে। কোনো node যদি DFS traversal-এর সময় recursion stack-এ থাকে, তাহলে সেটি একটি cycle নির্দেশ করে।

### DFS ভিত্তিক পদ্ধতি:

1. প্রতিটি node-এর জন্য DFS traversal চালানো হয়।
2. যদি কোনো node পুনরায় DFS stack-এ দেখা যায়, তবে সেখানে একটি cycle রয়েছে বলে ধরে নেওয়া হয়।

#### উদাহরণ:

নিচের গ্রাফে একটি directed cycle রয়েছে:

```
   1 → 2
   ↑   |
   |   ↓
   4 ← 3
```

এখানে 1 → 2 → 3 → 4 → 1 একটি cycle নির্দেশ করছে।

### C++ কোড (DFS ভিত্তিক):

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool isCyclicDFS(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (isCyclicDFS(neighbor, adj, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true; // Cycle detected
        }
    }

    recStack[node] = false; // Remove from recursion stack
    return false;
}

bool hasCycle(int n, vector<vector<int>> &adj) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (isCyclicDFS(i, adj, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0] = {1};
    adj[1] = {2};
    adj[2] = {3};
    adj[3] = {0};

    if (hasCycle(n, adj)) {
        cout << "Cycle detected" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}
```

এই কোডটি DFS পদ্ধতি ব্যবহার করে Directed Graph-এর মধ্যে cycle খুঁজে বের করে। `isCyclicDFS` ফাংশনটি প্রতিটি node-এর জন্য DFS চালিয়ে দেখে, যদি কোনো node আবার recursion stack-এ ফিরে আসে, তবে সেটি একটি cycle নির্দেশ করে।

### ২. **Kahn's Algorithm (Topological Sort-based Algorithm)**

Directed Acyclic Graph (DAG) এর ক্ষেত্রে Kahn's Algorithm ব্যবহার করে Topological Sort বের করা হয়। যদি Topological Sort বের করা সম্ভব না হয়, তাহলে Graph-এ cycle রয়েছে।

এই পদ্ধতিটি সাধারণত BFS ভিত্তিক এবং Directed Graph-এ cycle detect করার জন্য আরেকটি কার্যকর পদ্ধতি।

### কাহন'স অ্যালগরিদম ভিত্তিক পদ্ধতির সারাংশ:

- ইনডিগ্রি (in-degree) বের করা হয়, এবং ইনডিগ্রি 0 এমন node গুলো queue-তে রাখা হয়।
- এই node গুলো বের করে তার adjacency list update করা হয়।
- যদি সব node topologically sort করা যায় তবে cycle নেই, অন্যথায় cycle আছে।
