# Module 18

# 1 . Subset Sum Variation

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

# 2 . Count of Subset Sum Variation

**Count of Subset Sum Variation** হল একটি প্রোব্লেম, যেখানে তোমাকে একটি অ্যারেতে দেওয়া উপাদানগুলোর থেকে নির্দিষ্ট একটা টার্গেট সাম (sum) তৈরির জন্য কয়টা ভিন্ন ভিন্ন subset থাকতে পারে, সেটা বের করতে হয়।

এই সমস্যা খুবই পরিচিত এবং ডায়নামিক প্রোগ্রামিং (DP) দিয়ে সমাধান করা হয়। চল, একটু ব্যাখ্যা করি কীভাবে সমস্যাটা কাজ করে:

### সমস্যা বিবৃতি:

তোমাকে একটা অ্যারে দেওয়া আছে, ধরো `arr[] = {2, 3, 5, 6, 8, 10}` এবং একটা টার্গেট সাম `sum = 10`। এখন তোমাকে জানতে হবে, ক'টি ভিন্ন subset আছে যেগুলোর উপাদানগুলোর যোগফল ১০ হয়।

### উদাহরণ:

Input:

- `arr[] = {2, 3, 5, 6, 8, 10}`
- `sum = 10`

Output: 3

এখানে ৩টা subset আছে যেগুলোর যোগফল ১০ হয়:

- `{2, 3, 5}`
- `{10}`
- `{2, 8}`

### পদ্ধতি:

এই সমস্যাটা "Subset Sum Problem"-এর একটা ভেরিয়েশন, যেখানে কেবল তুমি জানতে চাও কতগুলো subset আছে নির্দিষ্ট সাম তৈরি করতে।

#### ডায়নামিক প্রোগ্রামিং (DP) ব্যবহার করে সমাধান:

তুমি একটা ২D টেবিল তৈরি করতে পারো যেখানে `dp[i][j]` সংরক্ষণ করবে কতগুলো subset আছে যেগুলো প্রথম `i` উপাদানের মধ্যে থেকে সাম `j` তৈরি করতে পারে।

#### Recursive Formula:

- যদি বর্তমান উপাদানটা নেওয়া সম্ভব হয় (i.e., `arr[i] <= j`), তাহলে আমাদের কাছে দুটি বিকল্প আছে:
  1. বর্তমান উপাদানটা না নিয়ে সাম তৈরি করা। অর্থাৎ, `dp[i-1][j]`.
  2. বর্তমান উপাদানটা নিয়ে সাম তৈরি করা। অর্থাৎ, `dp[i-1][j - arr[i]]`.

তাহলে,

```
dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i]]
```

- যদি বর্তমান উপাদানটা না নেওয়া যায় (i.e., `arr[i] > j`), তাহলে শুধু আগের অবস্থা নেওয়া যাবে:

```
dp[i][j] = dp[i-1][j]
```

### কোড উদাহরণ (C++):

```cpp
#include <iostream>
using namespace std;

int countSubsetSum(int arr[], int n, int sum) {
    int dp[n+1][sum+1];

    // যখন subset সাম ০ হয়, সেটার একটি সম্ভাবনা আছে: খালি subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    // যখন subset সাম > 0 হয় কিন্তু অ্যারেতে কোনো উপাদান না থাকে
    for (int j = 1; j <= sum; j++)
        dp[0][j] = 0;

    // DP টেবিল পূরণ করা
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] + dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Count of subsets with sum " << sum << " is: " << countSubsetSum(arr, n, sum) << endl;

    return 0;
}
```

### টাইম কমপ্লেক্সিটি:

- টাইম কমপ্লেক্সিটি: `O(n * sum)` (যেখানে `n` হল অ্যারের সাইজ এবং `sum` হল টার্গেট সাম)
- স্পেস কমপ্লেক্সিটি: `O(n * sum)`

এই ধরনের সমস্যায় ডায়নামিক প্রোগ্রামিং বেশ কার্যকরী সমাধান হতে পারে।

# 3 . Equal Sum Partition Variation

**Equal Sum Partition Variation** হল একটি সমস্যা, যেখানে তোমাকে একটি অ্যারে দেওয়া থাকে, এবং তোমাকে বের করতে হয়, অ্যারেটিকে কি এমনভাবে দুটি সাবসেটে বিভক্ত করা সম্ভব, যাতে সেই দুটি সাবসেটের যোগফল সমান হয়। এই সমস্যাটি **Partition Problem** নামেও পরিচিত।

### সমস্যা বিবৃতি:

তোমাকে একটি `arr[]` অ্যারে দেওয়া হলো। তোমাকে দেখতে হবে, এই অ্যারেটিকে কি দুটি সাবসেটে বিভক্ত করা সম্ভব, যাতে:

- সাবসেট দুটি হয় disjoint (অর্থাৎ, কোনো উপাদান দুইবার ব্যবহার করা যাবে না),
- দুটি সাবসেটের যোগফল সমান হয়।

### উদাহরণ:

**Input:**

```
arr[] = {1, 5, 11, 5}
```

**Output:**

```
Yes
Explanation: The array can be partitioned as {1, 5, 5} and {11}, and both subsets have the same sum.
```

**Input:**

```
arr[] = {1, 3, 5}
```

**Output:**

```
No
Explanation: The array cannot be partitioned into two subsets with equal sum.
```

### কীভাবে সমস্যাটি কাজ করে:

ধরি, অ্যারেটির মোট যোগফল \(S\)। এখন, যদি \(S\) বিজোড় (odd) হয়, তাহলে অ্যারেটিকে সমান দুটি সাবসেটে ভাগ করা কখনোই সম্ভব না, কারণ দুটি সমান সংখ্যার যোগফল কখনো বিজোড় হবে না। তাই, \(S\) যদি বিজোড় হয়, সোজাসুজি `No` রিটার্ন করা যায়।

যদি \(S\) জোড় হয়, তাহলে সমস্যাটা আসলে হয়ে দাঁড়ায় "Subset Sum Problem" যেখানে তোমাকে দেখতে হবে, অ্যারেটির মধ্যে এমন কোনো subset আছে কিনা, যার যোগফল \(S/2\) এর সমান। যদি এমন subset থাকে, তাহলে অ্যারেটিকে সমান দুটি অংশে ভাগ করা সম্ভব, অন্যথায় না।

### পদ্ধতি:

এই সমস্যাটাও ডায়নামিক প্রোগ্রামিং দিয়ে সমাধান করা যায়, যেখানে `Subset Sum Problem` এর পদ্ধতি ব্যবহার করা হয়।

### ধাপগুলো:

1. অ্যারেটির মোট যোগফল বের করো।
2. যদি যোগফল বিজোড় হয়, তাহলে `No` রিটার্ন করো।
3. যদি যোগফল জোড় হয়, তাহলে দেখতে হবে \(S/2\) সমান কোনো subset আছে কি না।
4. যদি \(S/2\) সমান subset থাকে, তাহলে অ্যারেটি সমান দুটি সাবসেটে ভাগ করা সম্ভব, অন্যথায় অসম্ভব।

### কোড উদাহরণ (C++):

```cpp
#include <iostream>
using namespace std;

bool subsetSum(int arr[], int n, int sum) {
    bool dp[n+1][sum+1];

    // যখন subset sum 0 হয়, সেটার একটা সম্ভাবনা থাকে: খালি subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    // যখন subset sum > 0 হয় কিন্তু কোনো উপাদান নেই
    for (int j = 1; j <= sum; j++)
        dp[0][j] = false;

    // DP টেবিল পূরণ করা
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][sum];
}

bool canPartition(int arr[], int n) {
    int sum = 0;

    // মোট যোগফল বের করো
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // যদি যোগফল বিজোড় হয়, সমান ভাগ করা সম্ভব না
    if (sum % 2 != 0)
        return false;

    // যদি যোগফল জোড় হয়, দেখতে হবে subset sum = sum/2 পাওয়া যায় কিনা
    return subsetSum(arr, n, sum / 2);
}

int main() {
    int arr[] = {1, 5, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (canPartition(arr, n))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
```

### ব্যাখ্যা:

1. **subsetSum()** ফাংশনটি মূলত subset sum বের করার জন্য ব্যবহৃত হয়। এটা `dp` টেবিল তৈরি করে যেখানে `dp[i][j]` সংরক্ষণ করে, প্রথম `i` উপাদানের মধ্যে থেকে `j` সমান subset তৈরি করা সম্ভব কি না।
2. **canPartition()** ফাংশনটি আগে অ্যারেটির মোট যোগফল বের করে। তারপর সেটা জোড় না বিজোড়, সেটা দেখে। যদি জোড় হয়, তাহলে `subsetSum()` ব্যবহার করে দেখা হয় \(S/2\) সমান subset পাওয়া যায় কিনা।

### টাইম কমপ্লেক্সিটি:

- টাইম কমপ্লেক্সিটি: `O(n * sum)` (যেখানে `n` হল অ্যারের সাইজ এবং `sum` হল টার্গেট সামের অর্ধেক)
- স্পেস কমপ্লেক্সিটি: `O(n * sum)`

# 4 . Minimum Subset Sum Difference

**Minimum Subset Sum Difference** একটি সমস্যা যেখানে তোমাকে একটি অ্যারে দেওয়া থাকে, এবং তোমাকে সেটিকে দুটি সাবসেটে ভাগ করতে হবে যেন তাদের যোগফলের মধ্যে পার্থক্য যতটা সম্ভব কম হয়। লক্ষ্য হলো সেই সর্বনিম্ন পার্থক্য বের করা।

### সমস্যা বিবৃতি:

তোমাকে একটি `arr[]` অ্যারে দেওয়া হলো। সেটিকে দুটি সাবসেটে ভাগ করতে হবে যাতে তাদের যোগফলের পার্থক্য কম হয়। তোমাকে সেই সর্বনিম্ন পার্থক্য বের করতে হবে।

### উদাহরণ:

**Input:**

```
arr[] = {1, 6, 11, 5}
```

**Output:**

```
1
Explanation: The array can be partitioned into two subsets {1, 6, 5} and {11}, and their sums are 12 and 11. The difference is 1.
```

### সমস্যাটি কীভাবে কাজ করে:

এই সমস্যাটি মূলত **Partition Problem** এর একটি ভেরিয়েশন। অ্যারেটির মোট যোগফল \(S\) বের করতে হবে। আমরা যদি অ্যারেটির একটি সাবসেট পাই যার যোগফল \(S_1\) এবং অন্য সাবসেটের যোগফল \(S_2\) হয়, তাহলে আমাদের লক্ষ্য হলো \(S_1\) এবং \(S_2\) এর পার্থক্য \(S_1 - S_2\) সর্বনিম্ন করা।

আমরা জানি, \(S_1 + S_2 = S\), তাই \(S_2 = S - S_1\)। সুতরাং, \(S_1 - S_2 = S_1 - (S - S_1) = 2S_1 - S\)। এখানে \(S_1\) হলো অ্যারেটির একটি subset এর যোগফল। লক্ষ্য হলো \(2S_1 - S\) কে সর্বনিম্ন করা।

### ধাপগুলো:

আমরা \(S_1\) বের করার চেষ্টা করব, যেটা \(S/2\) এর সমান বা কাছাকাছি। \(S_1\) যত \(S/2\) এর কাছাকাছি হবে, পার্থক্য ততই কম হবে।

### পদ্ধতি:

তুমি মূলত **Subset Sum Problem** সমাধানের মতো \(dp\) ব্যবহার করে বের করবে যে \(S/2\) এর কাছাকাছি যোগফল তৈরি করা সম্ভব কি না।

### উদাহরণ ব্যাখ্যা:

**Step 1:** প্রথমে অ্যারেটির মোট যোগফল বের করো।

```
arr[] = {1, 6, 11, 5}
Sum S = 1 + 6 + 11 + 5 = 23
```

আমাদের \(S/2 = 11.5\) এর কাছাকাছি subset খুঁজতে হবে।

**Step 2:** এখন ডাইনামিক প্রোগ্রামিং ব্যবহার করে দেখতে হবে \(S/2\) এর কাছাকাছি যোগফল বের করা সম্ভব কি না।

### কোড উদাহরণ (C++):

```cpp
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int minSubsetSumDifference(int arr[], int n) {
    // মোট যোগফল বের করো
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    // dp[i][j] সংরক্ষণ করবে যে প্রথম i উপাদান ব্যবহার করে j সমান subset তৈরি করা সম্ভব কি না
    bool dp[n+1][sum+1];

    // dp টেবিলের initialization
    for (int i = 0; i <= n; i++)
        dp[i][0] = true; // sum 0 হলে সবসময় সম্ভব (empty subset)

    for (int j = 1; j <= sum; j++)
        dp[0][j] = false; // কোন উপাদান না থাকলে sum != 0 করা সম্ভব না

    // DP টেবিল পূরণ করা
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i-1] <= j)
                dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    // সর্বনিম্ন পার্থক্য খুঁজে বের করো
    int minDiff = INT_MAX;
    for (int j = sum/2; j >= 0; j--) {
        if (dp[n][j]) {
            minDiff = sum - 2 * j;
            break;
        }
    }

    return minDiff;
}

int main() {
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The minimum difference between subset sums is: " << minSubsetSumDifference(arr, n) << endl;

    return 0;
}
```

### ব্যাখ্যা:

1. **DP Initialization:** `dp[i][j]` স্টেটটি দেখায় যে প্রথম `i`টি উপাদানের মাধ্যমে \(j\) সমান subset তৈরি করা সম্ভব কি না।
2. **DP Filling:** যদি \(arr[i-1] <= j\), তাহলে `dp[i][j] = dp[i-1][j] || dp[i-1][j - arr[i-1]]` হবে, অর্থাৎ, উপাদানটি নেওয়া সম্ভব হলে আমরা সেটা নিই, অথবা না নিই।
3. **Subset Sum:** আমরা \(S/2\) এর কাছাকাছি কোনো subset এর যোগফল খুঁজে বের করি। \(j\) যত \(S/2\) এর কাছাকাছি হবে, \(S - 2 \* j\) ততই ছোট হবে, এবং সেটা আমাদের পার্থক্য দেবে।

### টাইম কমপ্লেক্সিটি:

- টাইম কমপ্লেক্সিটি: \(O(n \* sum)\)
- স্পেস কমপ্লেক্সিটি: \(O(n \* sum)\)

# 5 . Count Number of Subsets with Given Difference

# 4 . Target Sum Variation
