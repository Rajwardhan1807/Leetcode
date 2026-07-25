# 125. Valid Palindrome

## 📌 Problem
Given a string `s`, determine whether it is a **palindrome** after:

- Converting all uppercase letters to lowercase.
- Removing all non-alphanumeric characters.
- Returning `true` if it reads the same forward and backward; otherwise, return `false`.

**LeetCode:** https://leetcode.com/problems/valid-palindrome/

---

## 💡 Approach

Use the **Two Pointers** technique.

- Initialize one pointer at the beginning (`left`) and another at the end (`right`).
- Ignore any non-alphanumeric characters using `isalnum()`.
- Compare characters after converting them to lowercase using `tolower()`.
- If they don't match, return `false`.
- Move both pointers inward until they cross.
- If no mismatch is found, return `true`.

---

## 🚀 Algorithm

1. Set `left = 0` and `right = s.length() - 1`.
2. While `left < right`:
   - Skip non-alphanumeric characters from the left.
   - Skip non-alphanumeric characters from the right.
   - Compare `tolower(s[left])` and `tolower(s[right])`.
   - If they differ, return `false`.
   - Otherwise, increment `left` and decrement `right`.
3. Return `true`.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (!isalnum(s[left])) {
                left++;
            }
            else if (!isalnum(s[right])) {
                right--;
            }
            else if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            else {
                left++;
                right--;
            }
        }

        return true;
    }
};
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |

- Each character is visited at most once.
- No extra data structures are used.

---

## 🧪 Example

### Example 1

**Input**
```text
"A man, a plan, a canal: Panama"
```

After removing non-alphanumeric characters and converting to lowercase:

```text
amanaplanacanalpanama
```

Output

```text
true
```

---

### Example 2

**Input**

```text
"race a car"
```

Processed string:

```text
raceacar
```

Output

```text
false
```

---

### Example 3

**Input**

```text
" "
```

Processed string:

```text
""
```

Output

```text
true
```

---

## 🔑 Key Concepts

- Two Pointers
- String Manipulation
- Character Functions (`isalnum`, `tolower`)
- Case-Insensitive Comparison

---

## 🎯 Takeaway

This problem demonstrates how the **Two Pointers** technique can efficiently compare characters from both ends of a string while skipping unwanted characters. It achieves **O(n)** time complexity with **constant space**, making it the optimal solution.