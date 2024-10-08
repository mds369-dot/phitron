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
