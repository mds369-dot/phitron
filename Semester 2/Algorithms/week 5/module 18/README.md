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

- Subset Sum Buttom Up

  2 . Count of Subset Sum Variation
  3 . Equal Sum Partition Variation
  4 . Minimum Subset Sum Difference
  5 . Count Number of Subsets with Given Difference
  4 . Target Sum Variation
