# 3. Longest Substring Without Repeating Characters

## Problem Statement

Given a string `s`, find the length of the longest substring without repeating characters.

### Examples

**Example 1**

```text
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with length 3.
```

**Example 2**

```text
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with length 1.
```

**Example 3**

```text
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with length 3.
```

---

## Approach

This solution uses the **Sliding Window** technique along with an `unordered_set` to efficiently track unique characters within the current window.

### Algorithm

1. Initialize two pointers:

   * `left` → Start of the window.
   * `right` → End of the window.

2. Use an `unordered_set` to store characters currently inside the window.

3. Expand the window by moving `right`.

4. If a duplicate character is found:

   * Remove characters from the left side of the window.
   * Move `left` forward until the duplicate is removed.

5. Update the maximum length after each valid window expansion.

---

## Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            while (seen.count(s[right])) {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
```

---

## Dry Run

### Input

```text
s = "abcabcbb"
```

| Window | Substring            | Length |
| ------ | -------------------- | ------ |
| a      | a                    | 1      |
| ab     | ab                   | 2      |
| abc    | abc                  | 3      |
| abca   | duplicate a → shrink | 3      |
| bcab   | duplicate b → shrink | 3      |
| cabc   | duplicate c → shrink | 3      |

Maximum length found = **3**

---

## Complexity Analysis

* **Time Complexity:** O(n)

  * Each character is inserted and removed at most once.

* **Space Complexity:** O(min(n, charset))

  * Stores unique characters currently inside the sliding window.

---

## Key Concepts

* Sliding Window
* Two Pointers
* Hash Set (`unordered_set`)
* String Manipulation

## LeetCode Link

Problem #3 - Longest Substring Without Repeating Characters
