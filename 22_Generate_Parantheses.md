# LeetCode 22 - Generate Parentheses

## Problem Statement

Given `n` pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

---

## Examples

### Example 1

```text
Input: n = 3

Output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
```

### Example 2

```text
Input: n = 1

Output:
[
  "()"
]
```

---

## Approach

This problem can be solved using **Backtracking**.

We build the parentheses string one character at a time while maintaining two counters:

* `open` → Number of opening parentheses `(` used.
* `close` → Number of closing parentheses `)` used.

### Rules

1. We can add an opening parenthesis `(` as long as `open < n`.
2. We can add a closing parenthesis `)` only if `close < open`.
3. Once the current string reaches a length of `2 × n`, it represents a valid combination and is added to the answer.

Backtracking explores every valid possibility while avoiding invalid states.

---

## Dry Run

### Input

```text
n = 2
```

### Recursive Generation

```text
Start: ""

Add "("
|
+-- "(("
|     |
|     +-- "(())"
|
+-- "()"
      |
      +-- "()()"
```

### Output

```text
[
  "(())",
  "()()"
]
```

---

## C++ Solution

```cpp
class Solution {
public:
    vector<string> ans;
    
    void backtrack(string curr, int open, int close, int n){
        if(curr.length() == 2 * n){
            ans.push_back(curr);
            return;
        }

        if(open < n){
            backtrack(curr + "(", open + 1, close, n);
        }

        if(close < open){
            backtrack(curr + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return ans;
    }
};
```

---

## Complexity Analysis

### Time Complexity

```text
O(4ⁿ / √n)
```

The number of valid parenthesis combinations is the **n-th Catalan Number**, which is approximately:

```text
4ⁿ / (n^(3/2) √π)
```

Thus, the overall time complexity is:

```text
O(4ⁿ / √n)
```

### Space Complexity

```text
O(n)
```

* Recursive call stack depth is at most `2n`.
* Excluding the output list, the auxiliary space used is `O(n)`.

---

## Concepts Used

* Backtracking
* Recursion
* Depth-First Search (DFS)
* String Construction

---

## LeetCode Details

* **Problem:** 22. Generate Parentheses
* **Difficulty:** Medium
* **Language:** C++
* **Approach:** Backtracking

---

This solution generates only valid parenthesis combinations by ensuring that the number of closing parentheses never exceeds the number of opening parentheses at any point during recursion.
