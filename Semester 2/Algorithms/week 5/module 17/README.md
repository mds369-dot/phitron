# Module 17

## 0 - 1 Knasack

- 0 - 1 means choice like 'Yes' or 'No'
- Knasack is Bay like 1 times only can use.

### In Bengla

0-1 Knapsack সমস্যা হল একটি ক্লাসিক্যাল ডায়নামিক প্রোগ্রামিং সমস্যা, যেখানে আপনাকে একটি ব্যাগের (knapsack) মধ্যে নির্দিষ্ট সীমিত ওজন (capacity) পর্যন্ত জিনিস (items) রাখা হয়, যাতে সেই জিনিসগুলোর মোট মান (value) সর্বাধিক হয়। প্রতিটি জিনিসের একটি নির্দিষ্ট ওজন এবং মান থাকে, এবং আপনি প্রতিটি জিনিস হয় নেবেন (1) অথবা নেবেন না (0), এই কারণেই একে 0-1 Knapsack বলা হয়।

### সমস্যা বিবরণ:

আপনার কাছে \( n \) টি জিনিস রয়েছে, প্রতিটি জিনিসের জন্য দুটি গুণ রয়েছে:

1. ওজন (weight)
2. মান (value)

আপনার টাস্ক হল এমন কিছু জিনিস বেছে নেওয়া, যাতে আপনার knapsack-এর মোট ওজন একটি নির্দিষ্ট সীমা \( W \) এর বেশি না হয় এবং এর মধ্যে রাখা জিনিসগুলোর মোট মান সর্বাধিক হয়।

### উদাহরণ:

ধরা যাক:

- \( n = 3 \) (তিনটি জিনিস আছে)
- জিনিসগুলোর ওজন: \([2, 3, 4]\)
- জিনিসগুলোর মান: \([3, 4, 5]\)
- knapsack-এর ওজন সীমা \( W = 5 \)

এক্ষেত্রে, আপনি জিনিসগুলো এইভাবে নির্বাচন করতে পারেন যে মোট ওজন 5-এর বেশি হবে না এবং মোট মান সর্বাধিক হবে।

### সমাধান পদ্ধতি:

- **Recursion**: প্রতিটি জিনিসের জন্য দুটি বিকল্প থাকে—জিনিসটি নেবেন বা নেবেন না। এইভাবে সমস্যার সমাধান করা যায়।
- **Dynamic Programming**: এটি একটি দক্ষ সমাধান পদ্ধতি যেখানে আমরা একটি টেবিল ব্যবহার করে পূর্ববর্তী ফলাফল সংরক্ষণ করি, যাতে পুনরায় গণনা করতে না হয়।

এই সমস্যার টাইম কমপ্লেক্সিটি সাধারণত \( O(n \times W) \), যেখানে \( n \) হল জিনিসের সংখ্যা এবং \( W \) হল ব্যাগের সীমা।

### In English

The **0-1 Knapsack problem** is a classic dynamic programming problem where you have a knapsack (bag) with a certain weight limit, and you are given a set of items, each with a specific weight and value. Your task is to maximize the total value of the items you can put in the knapsack without exceeding its weight limit. The "0-1" refers to the fact that each item can either be taken (1) or not taken (0), hence the name "0-1 Knapsack."

### Problem Description:

You are given \( n \) items, each with:

1. **Weight**: The weight of the item.
2. **Value**: The value of the item.

Your goal is to select a subset of items such that the total weight does not exceed a given capacity \( W \), and the total value of the selected items is maximized.

### Example:

Suppose:

- \( n = 3 \) (three items)
- The weights of the items are: \([2, 3, 4]\)
- The values of the items are: \([3, 4, 5]\)
- The knapsack's weight limit \( W = 5 \)

Here, you can choose items such that the total weight is less than or equal to 5, and the total value is maximized.

### Solution Approaches:

- **Recursion**: For each item, you have two choices—either take the item or don't. This can be solved using a recursive approach.
- **Dynamic Programming**: A more efficient solution uses a DP table to store the results of subproblems, avoiding redundant calculations. The time complexity of this approach is \( O(n \times W) \), where \( n \) is the number of items and \( W \) is the knapsack capacity.
