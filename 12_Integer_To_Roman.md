# 12. Integer to Roman

## Problem Statement

Given an integer `num`, convert it to its corresponding Roman numeral.

Roman numerals use the following symbols:

| Symbol | Value |
| ------ | ----: |
| I      |     1 |
| V      |     5 |
| X      |    10 |
| L      |    50 |
| C      |   100 |
| D      |   500 |
| M      |  1000 |

The input is guaranteed to be between **1** and **3999**.

---

## Example 1

```text
Input: num = 3749
Output: "MMMDCCXLIX"
```

## Example 2

```text
Input: num = 58
Output: "LVIII"
```

## Example 3

```text
Input: num = 1994
Output: "MCMXCIV"
```

---

## Approach

### Greedy Algorithm

Store all Roman numeral values in descending order, including special cases like:

* IV (4)
* IX (9)
* XL (40)
* XC (90)
* CD (400)
* CM (900)

Starting from the largest value:

1. If the current value is less than or equal to `num`, add its Roman symbol to the answer.
2. Subtract that value from `num`.
3. Repeat until `num` becomes `0`.

This greedy approach always produces the correct Roman numeral.

---

## Why This Works

We always choose the largest possible Roman numeral first.

For example, if:

```text
num = 58
```

Choose:

```text
50 → L
```

Remaining:

```text
8
```

Choose:

```text
5 → V
```

Remaining:

```text
3
```

Choose:

```text
1 → I
1 → I
1 → I
```

Final answer:

```text
LVIII
```

---

## Code

```cpp
class Solution {
public:
    string intToRoman(int num) {

        const vector<pair<int, string>> valueSym = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
        };

        string res;

        for (auto &[value, symbol] : valueSym) {
            while (num >= value) {
                res += symbol;
                num -= value;
            }
        }

        return res;
    }
};
```

---

## Dry Run

### Input

```text
num = 1994
```

Process:

```text
1000 → M
900  → CM
90   → XC
4    → IV
```

Final Answer:

```text
MCMXCIV
```

---

## Complexity Analysis

### Time Complexity

```text
O(1)
```

There are only **13 Roman numeral values**, so the loop runs a constant number of times.

### Space Complexity

```text
O(1)
```

Only the output string and a fixed-size lookup table are used.

---

## Key Concepts

* Greedy Algorithm
* Arrays
* String Manipulation
* Simulation

---

## LeetCode

**Problem #12 – Integer to Roman**

### Stats

* **Difficulty:** Medium
* **Acceptance Rate:** 71.2%
* **Topics:** Hash Table, Math, String

### Learning Outcome

This problem demonstrates how a **greedy algorithm** can efficiently solve conversion problems by always choosing the largest valid value first.
