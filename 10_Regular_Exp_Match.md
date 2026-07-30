# LeetCode 10 - Regular Expression Matching

## Problem Statement

Given an input string `s` and a pattern `p`, implement regular expression matching with support for:

* `.` → Matches any single character.
* `*` → Matches zero or more occurrences of the preceding element.

Return `true` if the pattern matches the **entire** string; otherwise, return `false`.

---

## Examples

### Example 1

```text
Input:
s = "aa"
p = "a"

Output:
false
```

Explanation:

```text
Pattern "a" matches only one character,
while the string contains two characters.
```

---

### Example 2

```text
Input:
s = "aa"
p = "a*"

Output:
true
```

Explanation:

```text
'*' allows the preceding character 'a'
to appear zero or more times.
```

---

### Example 3

```text
Input:
s = "ab"
p = ".*"

Output:
true
```

Explanation:

```text
'.' matches any character and
'*' allows it to repeat any number of times.
```

---

## Approach

This problem is solved using **Dynamic Programming**.

Let:

```text
dp[i][j]
```

represent whether the first `i` characters of `s` match the first `j` characters of `p`.

### Base Case

```text
dp[0][0] = true
```

An empty string matches an empty pattern.

---

## DP Transition

### Case 1: Current Pattern Character is `*`

There are two possibilities:

1. Ignore the preceding character and `*` (zero occurrences).

```text
dp[i][j] = dp[i][j-2]
```

2. Use one more occurrence of the preceding character.

This is valid only if:

* characters match, or
* preceding character is `.`

```text
dp[i][j] |= dp[i-1][j]
```

---

### Case 2: Normal Character or `.`

Current characters must match.

```text
dp[i][j] = dp[i-1][j-1]
```

only when

```text
s[i-1] == p[j-1]
```

or

```text
p[j-1] == '.'
```

---

## Dry Run

### Input

```text
s = "aa"
p = "a*"
```

DP Table:

| s \ p | "" | a | * |
| ----- | -- | - | - |
| ""    | T  | F | T |
| a     | F  | T | T |
| aa    | F  | F | T |

Final answer:

```text
true
```

---

## C++ Solution

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i = 0; i <= n; i++) {
            for(int j = 1; j <= m; j++) {

                if(p[j-1] == '*') {
                    dp[i][j] = dp[i][j-2] ||
                              (i > 0 &&
                              (s[i-1] == p[j-2] || p[j-2] == '.') &&
                               dp[i-1][j]);
                }
                else {
                    dp[i][j] = i > 0 &&
                               dp[i-1][j-1] &&
                              (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }

        return dp[n][m];
    }
};
```

---

## Complexity Analysis

### Time Complexity

```text
O(n × m)
```

Every DP state is computed once.

### Space Complexity

```text
O(n × m)
```

A `(n + 1) × (m + 1)` DP table is maintained.

---

## Concepts Used

* Dynamic Programming
* String Matching
* State Transition
* Regular Expressions

---

## LeetCode Details

* **Problem:** 10. Regular Expression Matching
* **Difficulty:** Hard
* **Language:** C++
* **Approach:** Dynamic Programming
* **Time Complexity:** O(n × m)
* **Space Complexity:** O(n × m)

---

The dynamic programming approach efficiently handles both special characters (`.` and `*`) by considering all valid matching possibilities while ensuring that the entire string is matched against the pattern.
