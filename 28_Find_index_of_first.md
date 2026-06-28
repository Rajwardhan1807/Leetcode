# 28. Find the Index of the First Occurrence in a String

## Problem Statement

Given two strings `haystack` and `needle`, return the **index of the first occurrence** of `needle` in `haystack`.

If `needle` is not present, return **-1**.

---

## Example 1

```text
Input:
haystack = "sadbutsad"
needle = "sad"

Output:
0
```

**Explanation**

The substring `"sad"` appears at indices **0** and **6**.

Since we need the **first occurrence**, the answer is **0**.

---

## Example 2

```text
Input:
haystack = "leetcode"
needle = "leeto"

Output:
-1
```

---

## Approach

### Brute Force (Character-by-Character Matching)

Instead of creating a substring using `substr()`, compare characters directly.

1. Try every possible starting position in `haystack`.
2. Compare each character of `needle` with the corresponding character in `haystack`.
3. If every character matches, return the starting index.
4. If a mismatch occurs, move to the next starting position.
5. If no match is found, return `-1`.

---

## Why This Works

Suppose:

```text
haystack = "sadbutsad"
needle = "sad"
```

Check from index **0**:

```text
haystack : s a d b u t s a d
           ↑ ↑ ↑
needle   : s a d
```

All characters match, so return **0**.

If characters didn't match, we'd simply move to the next index and try again.

---

## Code

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {

        int h = haystack.size();
        int n = needle.size();

        // Try every possible starting index
        for(int i = 0; i <= h - n; i++) {

            int j;

            // Compare characters one by one
            for(j = 0; j < n; j++) {
                if(haystack[i + j] != needle[j])
                    break;
            }

            // Entire needle matched
            if(j == n)
                return i;
        }

        return -1;
    }
};
```

---

## Dry Run

### Input

```text
haystack = "sadbutsad"
needle = "sad"
```

Start at index **0**:

```text
haystack : s a d b u t s a d
           ↑ ↑ ↑
needle   : s a d
```

* `s == s` ✅
* `a == a` ✅
* `d == d` ✅

All characters matched.

Return:

```text
0
```

---

## Complexity Analysis

### Time Complexity

```text
O((H - N + 1) × N)
```

Where:

* `H` = length of `haystack`
* `N` = length of `needle`

In the worst case, we compare all `N` characters at every valid starting position.

---

### Space Complexity

```text
O(1)
```

Only a few variables are used. No extra strings are created.

---

## Key Concepts

* Strings
* Brute Force
* Nested Loops
* Character-by-Character Comparison

---

## LeetCode

**Problem #28 – Find the Index of the First Occurrence in a String**

### Stats

* **Difficulty:** Easy
* **Runtime:** **0 ms (Beats 100%)**
* **Memory:** **8.95 MB (Beats 92.11%)**
* **Topics:** String, Brute Force

### Learning Outcome

This solution is a classic **naive string matching algorithm**. It avoids creating temporary substrings by comparing characters directly, making it more memory-efficient than the `substr()` approach. It also builds the intuition needed for advanced string matching algorithms like **KMP** and **Rabin-Karp**.
