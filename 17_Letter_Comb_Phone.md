# 17. Letter Combinations of a Phone Number

## Problem Statement

Given a string `digits` containing digits from **2 to 9**, return all possible letter combinations that the number could represent.

The mapping follows a standard phone keypad:

| Digit | Letters |
| ----: | ------- |
|     2 | abc     |
|     3 | def     |
|     4 | ghi     |
|     5 | jkl     |
|     6 | mno     |
|     7 | pqrs    |
|     8 | tuv     |
|     9 | wxyz    |

Return the combinations in **any order**.

---

## Example 1

```text
Input: digits = "23"

Output:
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

## Example 2

```text
Input: digits = "2"

Output:
["a","b","c"]
```

---

## Approach

### Backtracking (Recursion)

Think of each digit as a group of letters.

For every digit:

1. Pick one letter.
2. Move to the next digit.
3. Continue until every digit has been processed.
4. Store the completed combination.
5. Backtrack and try the next letter.

This explores every possible combination.

---

## Why This Works

For the input:

```text
23
```

Digit mapping:

```text
2 → abc
3 → def
```

Build combinations like:

```text
a → d → ad
a → e → ae
a → f → af

b → d → bd
b → e → be
b → f → bf

c → d → cd
c → e → ce
c → f → cf
```

Every possible choice is explored exactly once.

---

## Code

```cpp
class Solution {
public:

    vector<string> ans;

    vector<string> keypad = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    void solve(string &digits, int index, string current) {

        if(index == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = keypad[digits[index] - '0'];

        for(char ch : letters) {
            solve(digits, index + 1, current + ch);
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        solve(digits, 0, "");

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
digits = "23"
```

Start:

```text
""
```

Choose from digit `2`:

```text
a
b
c
```

For `a`, choose from digit `3`:

```text
ad
ae
af
```

For `b`:

```text
bd
be
bf
```

For `c`:

```text
cd
ce
cf
```

Final Answer:

```text
["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

---

## Complexity Analysis

### Time Complexity

```text
O(4^N)
```

* Each digit has at most **4** possible letters.
* For `N` digits, there can be at most **4ⁿ** combinations.

### Space Complexity

```text
O(N)
```

* Recursive call stack stores at most `N` characters.
* (Ignoring the space required for the output.)

---

## Key Concepts

* Backtracking
* Recursion
* Strings
* DFS (Depth-First Search)

---

## LeetCode

**Problem #17 – Letter Combinations of a Phone Number**

### Stats

* **Difficulty:** Medium
* **Acceptance Rate:** 66.3%
* **Topics:** Hash Table, String, Backtracking

### Learning Outcome

This problem is an excellent introduction to **backtracking**. It demonstrates how recursion can systematically generate every possible combination by making a choice, exploring it, and then backtracking to try the next option.
