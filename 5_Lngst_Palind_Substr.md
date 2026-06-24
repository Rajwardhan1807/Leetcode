# 5. Longest Palindromic Substring

## Problem Statement

Given a string `s`, return the longest palindromic substring in `s`.

A palindrome is a string that reads the same forward and backward.

---

## Example 1

```text
Input: s = "babad"
Output: "bab"
```

**Explanation:** `"bab"` and `"aba"` are both valid answers.

### Example 2

```text
Input: s = "cbbd"
Output: "bb"
```

---

## Approach

### Expand Around Center

A palindrome expands equally on both sides from its center.

For every character in the string:

* Check for an **odd-length palindrome** (like `"racecar"`).
* Check for an **even-length palindrome** (like `"abba"`).
* Keep expanding left and right while the characters are the same.
* Store the longest palindrome found.

### Example

For `"babad"`:

```text
b a b a d
    ^
```

Starting from the center `'b'`, we can expand and get:

```text
bab
```

Similarly, checking other centers may give:

```text
aba
```

The longest palindrome length is `3`.

---

## Code

```cpp
class Solution {
public:
    string longestPalindrome(string s) {

        string res = "";

        for(int i = 0; i < s.size(); i++) {

            // Odd Length Palindrome
            int st = i;
            int end = i;

            while(st >= 0 && end < s.size() &&
                  s[st] == s[end]) {
                st--;
                end++;
            }

            string temp = s.substr(st + 1, end - st - 1);

            if(temp.size() > res.size())
                res = temp;

            // Even Length Palindrome
            st = i;
            end = i + 1;

            while(st >= 0 && end < s.size() &&
                  s[st] == s[end]) {
                st--;
                end++;
            }

            temp = s.substr(st + 1, end - st - 1);

            if(temp.size() > res.size())
                res = temp;
        }

        return res;
    }
};
```

---

## Dry Run

### Input

```text
s = "cbbd"
```

Checking between the two `'b'` characters:

```text
c b b d
  ^ ^
```

Expand outward:

```text
bb
```

Longest palindrome:

```text
bb
```

---

## Complexity Analysis

### Time Complexity

```text
O(N²)
```

For every character, we may expand across the string.

### Space Complexity

```text
O(1)
```

No extra data structures are used.

---

## Key Concepts

* Strings
* Two Pointers
* Expand Around Center
* Palindrome Detection

---

## LeetCode

**Problem #5 – Longest Palindromic Substring**
