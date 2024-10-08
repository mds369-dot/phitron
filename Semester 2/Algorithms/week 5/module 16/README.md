# Module 16

## Dynamic Programming (DP)

Dynamic Programming (DP) is an optimization technique used to solve problems by breaking them down into overlapping subproblems and storing the results of these subproblems to avoid redundant calculations. This approach is particularly useful for problems that exhibit two key properties:

1. **Optimal Substructure**: The solution to a given problem can be derived from the solutions to its smaller subproblems.
2. **Overlapping Subproblems**: The same subproblems are solved multiple times. By storing their solutions (usually in a table), DP ensures that each subproblem is solved only once.

### Steps for Dynamic Programming:

1. **Define the Subproblems**: Identify smaller instances of the problem that can be solved recursively.
2. **Recursive Relation**: Formulate a recurrence relation that relates the solution of the subproblem to larger problems.

3. **Memoization or Tabulation**:

   - **Memoization** (Top-Down Approach): Solve the problem recursively and store the results of subproblems in a table (usually an array or map) to avoid recalculating.
   - **Tabulation** (Bottom-Up Approach): Iteratively solve all subproblems starting from the smallest, filling up a table until the final solution is reached.

4. **Solve the Base Case**: Handle the simplest version of the problem (base case) directly.

### Example: Fibonacci Sequence (using DP)

The Fibonacci sequence can be defined as:
\[ F(n) = F(n-1) + F(n-2) \]
with base cases \( F(0) = 0 \) and \( F(1) = 1 \).

#### Recursive (Inefficient):

```cpp
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}
```

This has an exponential time complexity because of redundant calculations.

#### Using DP (Efficient):

```cpp
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n];
}
```

This approach reduces the time complexity to \( O(n) \) by storing previously computed results.

### Common Problems Solved Using DP:

- **Knapsack problem**
- **Longest Common Subsequence**
- **Matrix Chain Multiplication**
- **Coin Change Problem**
- **Edit Distance**

### Optimization Techniques:

- **Space Optimization**: Instead of storing the results of all subproblems, you can often reduce space usage by only keeping track of the last few computed results.

Would you like to explore a specific DP problem or have an example coded in C++?

# Factorial

The **factorial** of a non-negative integer `n`, denoted as `n!`, is the product of all positive integers less than or equal to `n`. The factorial can be defined as:

\[
n! = n \times (n - 1) \times (n - 2) \times \dots \times 1
\]
with the base case:
\[
0! = 1
\]

### Factorial using Dynamic Programming

The factorial problem doesn’t exhibit overlapping subproblems like many typical DP problems, so a direct recursive or iterative solution is usually preferred. However, you can still use dynamic programming (with tabulation) to compute the factorial efficiently by storing intermediate results.

#### Iterative Approach (Using Tabulation)

Here’s how we can compute the factorial using an iterative approach, which is similar to the idea of tabulation in dynamic programming:

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1; // Base case: 0! = 1

    int fact[n+1]; // Array to store results of subproblems
    fact[0] = 1;   // 0! = 1

    // Compute factorial iteratively
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i-1] * i;
    }

    return fact[n]; // Return the result for n!
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
```

### Recursive Approach (Without DP)

You can also calculate factorial recursively, although this approach doesn’t make use of dynamic programming.

```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1; // Base case: 0! = 1
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;
    return 0;
}
```

### Time Complexity:

- Both the recursive and iterative solutions have a time complexity of \(O(n)\) because they involve multiplying the numbers from 1 to `n`.

Would you like further explanation on the DP-like tabulation for this, or are you interested in exploring a more complex factorial-based problem?

# Fibonacci Series Recurvise Solution (FSRS)

The **Fibonacci series** is a sequence of numbers where each number is the sum of the two preceding ones, usually starting with 0 and 1. Mathematically, it can be defined as:

\[
F(n) =
\begin{cases}
0 & \text{if } n = 0 \\
1 & \text{if } n = 1 \\
F(n-1) + F(n-2) & \text{if } n > 1
\end{cases}
\]

### Recursive Solution for Fibonacci Series

The recursive solution follows directly from the mathematical definition, where we call the function recursively to calculate `F(n-1)` and `F(n-2)` until we reach the base cases.

Here is the C++ implementation:

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Recursive calls to find Fibonacci of n-1 and n-2
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}
```

### Explanation:

- **Base Case**: If `n` is 0, the function returns 0, and if `n` is 1, it returns 1.
- **Recursive Case**: For `n > 1`, the function recursively calls itself to compute `F(n-1)` and `F(n-2)`.

### Time Complexity:

The time complexity of this recursive solution is **O(2^n)**, which is quite inefficient. This is because the function recalculates the Fibonacci values for the same input multiple times.

### Example:

If you input `n = 5`, the function will calculate:

\[
F(5) = F(4) + F(3) = (F(3) + F(2)) + (F(2) + F(1)) = ((F(2) + F(1)) + (F(1) + F(0))) + ((F(1) + F(0)) + 1)
\]

This approach leads to redundant calculations of the same Fibonacci numbers, which makes the recursive method inefficient for large `n`.

### Optimizing the Recursive Approach:

To optimize the recursive solution, you can use **memoization** (storing previously computed values) or switch to an **iterative** solution, which brings down the time complexity to **O(n)**.

Would you like to see the optimized recursive version with memoization, or is this explanation enough?

# Fibonacci showing in graph

- [Function and Graph Shwing Website](https://quanticdev.com/tools/recursion-visualization/)

# Fibonacci Buttom Up

The **bottom-up approach** for the Fibonacci series is an optimized way of solving the problem iteratively by building the solution from smaller subproblems. Instead of recalculating the Fibonacci value for each number multiple times (as in the recursive approach), we calculate and store the Fibonacci numbers in a table (array), starting from the smallest values, and use these to calculate the larger ones.

### Bottom-Up Fibonacci (Tabulation)

Here’s the C++ implementation using the bottom-up dynamic programming approach:

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Create an array to store Fibonacci numbers
    int fib[n+1];

    // Base cases
    fib[0] = 0;
    fib[1] = 1;

    // Fill the array from the bottom up
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }

    return fib[n]; // Return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}
```

### Explanation:

1. **Base Case**: If `n` is 0, return 0; if `n` is 1, return 1. These are the two base cases of the Fibonacci series.
2. **Table Initialization**: An array `fib[]` is created to store the Fibonacci numbers. `fib[0]` is initialized to 0, and `fib[1]` is initialized to 1.
3. **Iteration**: Starting from index 2, we compute each Fibonacci number as the sum of the two preceding numbers: `fib[i] = fib[i-1] + fib[i-2]`.
4. **Final Answer**: The nth Fibonacci number is returned at the end.

### Time and Space Complexity:

- **Time Complexity**: \( O(n) \) because we compute each Fibonacci number exactly once.
- **Space Complexity**: \( O(n) \) because we are storing the Fibonacci numbers in an array.

### Space-Optimized Version

We can further optimize the space complexity to \( O(1) \) by only keeping track of the last two Fibonacci numbers instead of storing all of them:

```cpp
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev2 = 0, prev1 = 1; // To store fib(n-2) and fib(n-1)
    int curr;

    // Compute Fibonacci iteratively without using extra space
    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2;  // Calculate current Fibonacci
        prev2 = prev1;         // Shift the values
        prev1 = curr;
    }

    return curr; // Return the nth Fibonacci number
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "Fibonacci of " << n << " is " << fibonacci(n) << endl;
    return 0;
}
```

### Explanation of Space Optimization:

- Instead of using an array, we only store the last two Fibonacci numbers (`prev2` and `prev1`), which are updated as we compute the current Fibonacci number. This reduces the space complexity to \( O(1) \), while keeping the time complexity at \( O(n) \).

Would you like more explanation on the space optimization or try some related problems?
