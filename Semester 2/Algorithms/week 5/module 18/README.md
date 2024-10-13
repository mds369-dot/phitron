# Module 18

1 . Subset Sum Variation

- Subset Sum Top Down
  **Subset Sum (Top Down Approach)** হল ডাইনামিক প্রোগ্রামিং পদ্ধতি যা একটি নির্দিষ্ট লক্ষ্য `target` (বা `sum`) পাওয়া সম্ভব কিনা তা নির্ধারণ করে একটি দেওয়া `array` থেকে কিছু উপাদান নিয়ে।

### সমস্যার বিবরণ:

তুমি একটি ধনাত্মক পূর্ণসংখ্যার `array` এবং একটি `target sum` পাবে। তোমার কাজ হলো যাচাই করা যে, সেই `array` থেকে কিছু উপাদান নিয়ে সেই `target sum` করা সম্ভব কি না।

### Top-Down Approach (Memoization):

এই পদ্ধতিতে সমস্যাকে ছোট ছোট সাব-প্রবলেমে ভেঙে ফেলা হয় এবং একই সাব-প্রবলেম বারবার সমাধান এড়াতে মেমোইজেশন ব্যবহার করা হয়।

#### 1. **Recursive Solution**:

প্রথমে একটি পুনরাবৃত্তিমূলক (recursive) সমাধান তৈরি করা হয়, যেখানে আমরা প্রতিটি উপাদানকে ২ভাবে বিবেচনা করি:

- উপাদানটিকে অন্তর্ভুক্ত করা।
- উপাদানটিকে বাদ দেওয়া।

#### 2. **Memoization**:

যখনই কোনও সাব-প্রবলেমের সমাধান করা হয়, তা একটি `dp` array (বা ২D array) তে সংরক্ষণ করা হয়, যাতে পরবর্তীতে একই সাব-প্রবলেমে আবার যেতে না হয়।

### Recursive Relation:

একটি উপাদান `arr[i]` থাকলে, তুমি দুটি সম্ভাবনা আছে:

1. তুমি `arr[i]` কে ব্যবহার করবে।
2. তুমি `arr[i]` কে ব্যবহার করবে না।

তাহলে, সমস্যা এভাবে সমাধান হয়:

```
SubsetSum(arr, n, sum) =
    SubsetSum(arr, n-1, sum) OR
    SubsetSum(arr, n-1, sum - arr[n-1])
```

#### Base Case:

- যদি `sum == 0`, তাহলে সেটি সম্ভব (empty set দিয়ে `sum` পাওয়া সম্ভব)।
- যদি `n == 0` এবং `sum != 0`, তাহলে এটি অসম্ভব।

### C++ Top Down Implementation:

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool subsetSumUtil(vector<int>& arr, int n, int sum, vector<vector<int>>& dp) {
    // Base Cases
    if (sum == 0) return true;  // sum 0 হলে সেটি সম্ভব
    if (n == 0) return false;   // উপাদান না থাকলে এবং sum != 0 হলে অসম্ভব

    // যদি পূর্বেই মেমোইজেশন করা থাকে
    if (dp[n][sum] != -1) return dp[n][sum];

    // উপাদানটি অন্তর্ভুক্ত না করে সমাধান
    bool exclude = subsetSumUtil(arr, n - 1, sum, dp);

    // উপাদানটি অন্তর্ভুক্ত করলে এবং এটি sum এর চেয়ে ছোট বা সমান
    bool include = false;
    if (arr[n - 1] <= sum) {
        include = subsetSumUtil(arr, n - 1, sum - arr[n - 1], dp);
    }

    // মেমোইজেশনের জন্য মান সংরক্ষণ
    dp[n][sum] = include || exclude;
    return dp[n][sum];
}

bool subsetSum(vector<int>& arr, int sum) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));  // মেমোইজেশন টেবিল
    return subsetSumUtil(arr, n, sum, dp);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    if (subsetSum(arr, sum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }
    return 0;
}
```

### কীভাবে কাজ করে:

1. প্রথমে বেস কেসগুলো পরীক্ষা করা হয়।
2. তারপর, মেমোইজেশন করা `dp` array ব্যবহার করা হয় যাতে বারবার একই সমস্যার সমাধান করতে না হয়।
3. উপাদানগুলোকে অন্তর্ভুক্ত বা বাদ দিয়ে সমস্যার সমাধান খোঁজা হয়।
4. শেষ পর্যন্ত `dp[n][sum]` জানাবে, `target sum` সম্ভব কি না।

### Time Complexity:

- Top-Down পদ্ধতির সময় জটিলতা হলো `O(n * sum)` যেখানে `n` হলো উপাদানের সংখ্যা এবং `sum` হলো টার্গেট মান।

- Subset Sum Bottom Up
  **Subset Sum (Bottom-Up Approach)** হল ডাইনামিক প্রোগ্রামিং-এর আরও একটি পদ্ধতি, যেখানে সমস্যার ছোট ছোট উপ-সমস্যাগুলোর সমাধান থেকে ধীরে ধীরে বড় সমস্যার সমাধানে আসা হয়। Bottom-Up পদ্ধতিতে আমরা একটি টেবিল ব্যবহার করে সমস্যার সমাধান তৈরি করি, যাতে মেমোইজেশন বা পুনরাবৃত্তিমূলক পদ্ধতির (Top-Down) প্রয়োজন না হয়।

### সমস্যার বিবরণ:

তুমি একটি ধনাত্মক পূর্ণসংখ্যার `array` এবং একটি `target sum` পাবে। তোমার কাজ হলো যাচাই করা যে, সেই `array` থেকে কিছু উপাদান নিয়ে সেই `target sum` করা সম্ভব কি না।

### Bottom-Up Dynamic Programming (Tabulation) পদ্ধতি:

এই পদ্ধতিতে আমরা একটি টেবিল তৈরি করি, যেখানে প্রতিটি ইনডেক্স জানাবে, সংশ্লিষ্ট টার্গেট পর্যন্ত পৌঁছানো সম্ভব কি না।

### Bottom-Up Approach-এর আইডিয়া:

- আমরা একটি `dp` টেবিল তৈরি করব যেখানে `dp[i][j]` হবে `true` যদি `array` এর প্রথম `i`টি উপাদান থেকে `sum j` তৈরি করা যায়, অন্যথায় `false`।
- ধীরে ধীরে ছোট উপ-সমস্যাগুলো সমাধান করে বড় সমস্যায় পৌঁছানো হবে।

### State Transition:

- যদি আমরা একটি উপাদান অন্তর্ভুক্ত না করি, তাহলে `dp[i][j] = dp[i-1][j]`
- যদি আমরা একটি উপাদান অন্তর্ভুক্ত করি, তাহলে `dp[i][j] = dp[i-1][j-arr[i-1]]`

### Base Case:

- `dp[0][0] = true`, কারণ 0 `sum` খালি সেট দিয়ে পাওয়া সম্ভব।
- অন্য সব `dp[0][j] = false`, যেখানে `j != 0`, কারণ কোনো উপাদান ছাড়াই কোনো non-zero `sum` তৈরি করা সম্ভব নয়।

### C++ Bottom-Up Implementation:

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int targetSum) {
    int n = arr.size();
    // dp টেবিল তৈরি করা, যেখানে dp[i][j] true হলে, j sum সম্ভব i উপাদান পর্যন্ত
    vector<vector<bool>> dp(n + 1, vector<bool>(targetSum + 1, false));

    // বেস কেস: 0 sum তৈরি করা সব ক্ষেত্রেই সম্ভব (খালি সেট দিয়ে)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }

    // ডাইনামিক প্রোগ্রামিং টেবিল পূরণ করা
    for (int i = 1; i <= n; i++) {
        for (int sum = 1; sum <= targetSum; sum++) {
            // উপাদানটি অন্তর্ভুক্ত না করলে
            dp[i][sum] = dp[i-1][sum];

            // উপাদানটি অন্তর্ভুক্ত করলে
            if (arr[i-1] <= sum) {
                dp[i][sum] = dp[i][sum] || dp[i-1][sum - arr[i-1]];
            }
        }
    }

    // ফলাফল টেবিলের শেষে থাকবে
    return dp[n][targetSum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    if (subsetSum(arr, targetSum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }
    return 0;
}
```

### ব্যাখ্যা:

1. **dp Table:** আমরা একটি 2D টেবিল ব্যবহার করি, যেখানে `dp[i][sum]` সংরক্ষণ করে যে, প্রথম `i`টি উপাদান দিয়ে `sum` তৈরি করা সম্ভব কি না।
2. **ট্রানজিশন:** আমরা প্রতিটি উপাদান যোগ করি বা বাদ দিই এবং সেই অনুযায়ী টেবিল আপডেট করি।
3. **ফলাফল:** টেবিলের শেষে, `dp[n][targetSum]` আমাদের বলে যে, পুরো অ্যারের মধ্যে থেকে `targetSum` তৈরি করা সম্ভব কি না।

### Time Complexity:

- **Time Complexity:** `O(n * targetSum)`, যেখানে `n` হলো উপাদানগুলোর সংখ্যা এবং `targetSum` হলো টার্গেট মান।
- **Space Complexity:** `O(n * targetSum)` টেবিলের জন্য। (এটি `O(targetSum)` এ কমানো সম্ভব একমাত্র ১টি ডাইমেনশনে কাজ করলে।)

### Space Optimization:

এই সমস্যার স্থান জটিলতা আরও উন্নত করা সম্ভব, কারণ আমরা শুধু আগের সারি থেকে তথ্য ব্যবহার করছি। এর জন্য 2D টেবিলের পরিবর্তে একটি 1D টেবিল ব্যবহার করা যায়, যা নিম্নরূপ:

```cpp
#include <iostream>
#include <vector>
using namespace std;

bool subsetSum(vector<int>& arr, int targetSum) {
    int n = arr.size();
    // 1D dp টেবিল
    vector<bool> dp(targetSum + 1, false);
    dp[0] = true; // 0 sum সবসময় সম্ভব

    for (int i = 0; i < n; i++) {
        for (int sum = targetSum; sum >= arr[i]; sum--) {
            dp[sum] = dp[sum] || dp[sum - arr[i]];
        }
    }

    return dp[targetSum];
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int targetSum = 9;
    if (subsetSum(arr, targetSum)) {
        cout << "Subset with the given sum exists." << endl;
    } else {
        cout << "Subset with the given sum does not exist." << endl;
    }
    return 0;
}
```

### Summary:

Bottom-Up পদ্ধতিতে ছোট থেকে বড় সমস্যার সমাধান করা হয় এবং ডাইনামিক প্রোগ্রামিং টেবিল পূরণ করে আমরা সমস্যার সমাধান করি।

2 . Count of Subset Sum Variation
3 . Equal Sum Partition Variation
4 . Minimum Subset Sum Difference
5 . Count Number of Subsets with Given Difference
4 . Target Sum Variation
