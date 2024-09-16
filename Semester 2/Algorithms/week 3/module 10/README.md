# Module 10

## DSU (Disjoint Set Union)

### Disjoint Set

**Disjoint Set Union (DSU)**, যাকে **Union-Find** ডেটা স্ট্রাকচারও বলা হয়, এটি একটি ডেটা স্ট্রাকচার যা কিছু ভিন্ন সেটকে ম্যানেজ করতে ব্যবহৃত হয়। এর মাধ্যমে মূলত দুটি প্রধান অপারেশন করা যায়:

1. **Find (খুঁজে বের করা):** এই অপারেশনটি নির্ধারণ করে যে কোন একটি এলিমেন্ট কোন সেটের সদস্য।
2. **Union (দুই সেটকে একত্রিত করা):** এই অপারেশনটি দুটি সেটকে একত্রিত করে একটি একক সেটে পরিণত করে।

### DSU-এর প্রধান কাজ

- **Set Finding:** একাধিক সেটের মধ্যে কোনো নির্দিষ্ট এলিমেন্ট কোন সেটের অন্তর্গত তা খুঁজে বের করা।
- **Union:** দুটি সেটকে একত্রিত করা এবং তাদেরকে একটি সেট হিসেবে বিবেচনা করা।

### উদাহরণ:

ধরা যাক, প্রথমে প্রতিটি এলিমেন্ট নিজেই একটি স্বতন্ত্র সেটে আছে। DSU দিয়ে আমরা দুইটি সেটকে মিলে একত্রিত করতে পারি এবং তাদের মধ্যে সম্পর্ক তৈরি করতে পারি।

### DSU-এর কিছু বৈশিষ্ট্য:

1. **Path Compression:** `Find` অপারেশনকে আরও দ্রুত করার জন্য একটি অপটিমাইজেশন, যাতে কোনো এলিমেন্টের প্যারেন্ট সেটকে সরাসরি সেটের প্রধানের সাথে সংযুক্ত করা হয়।
2. **Union by Rank:** `Union` অপারেশনকে আরও দ্রুত করতে এই অপটিমাইজেশন ব্যবহার করা হয়, যাতে সবসময় ছোট সেটকে বড় সেটের সাথে যুক্ত করা হয়।

### Time Complexity:

DSU অপারেশনগুলো সাধারণত খুব দ্রুত কাজ করে। প্রায় প্রতিটি অপারেশনের সময় লাগে প্রায় **O(α(n))**, যেখানে **α(n)** হল inverse Ackermann function, যা প্রায় প্রায়শই constant এর সমান ধরা হয়।

### ব্যবহার:

- গ্রাফে connected components খুঁজে বের করতে।
- MST (Minimum Spanning Tree) বের করতে, যেমন Kruskal’s Algorithm-এ।

DSU একটি খুব গুরুত্বপূর্ণ এবং কার্যকরী ডেটা স্ট্রাকচার, যা কমপ্লেক্স সমস্যাগুলোতে efficient সমাধান দিতে সাহায্য করে।

```
find()
union()
```

### DSU find code

```
int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = find(par[node]);
    par[node] = leader;
    return leader;
}
```

### DSU Union

```
void dsu_union(int node1, int node2)
{

    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    par[leaderA] = leaderB;
}
```

### DSU Union by Size

```
void dsu_union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if (group_size[leaderA] > group_size[leaderB])
    {
        par[leaderB] = leaderA;
        group_size[leaderA] += group_size[leaderB];
    }
    else
    {
        par[leaderA] = leaderB;
        group_size[leaderB] += group_size[leaderA];
    }
}
```
