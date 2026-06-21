# 13_Roman_To_Integer

## Problem

Roman numerals are represented by different letters:

| Symbol | Value |
| ------ | ----- |
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Given a Roman numeral string `s`, convert it into an integer.

---

## Example

### Example 1

Input:

```text
s = "III"
```

Output:

```text
3
```

Explanation:

```text
I + I + I = 3
```

---

### Example 2

Input:

```text
s = "LVIII"
```

Output:

```text
58
```

Explanation:

```text
L = 50
V = 5
III = 3

50 + 5 + 3 = 58
```

---

### Example 3

Input:

```text
s = "MCMXCIV"
```

Output:

```text
1994
```

Explanation:

```text
M    = 1000
CM   = 900
XC   = 90
IV   = 4

1000 + 900 + 90 + 4 = 1994
```

---

## Simple Explanation (Like a 2-Year-Old)

Imagine Roman letters are treasure boxes.

```text
I = 1 coin
V = 5 coins
X = 10 coins
```

Normally, we add the coins:

```text
VI = 5 + 1 = 6
```

But sometimes a smaller number comes before a bigger one:

```text
IV
```

Here:

```text
1 comes before 5
```

So instead of adding:

```text
1 + 5
```

we subtract:

```text
5 - 1 = 4
```

That's the special rule of Roman numerals.

---

## Approach

1. Store all Roman symbols and their values in a hash map.
2. Traverse the string from left to right.
3. Compare the current symbol with the next symbol.
4. If the current value is smaller than the next value:

   * Subtract it from the result.
5. Otherwise:

   * Add it to the result.
6. Return the final result.

---

## Dry Run

Input:

```text
s = "MCMXCIV"
```

Step-by-step:

| Current  | Next     | Action   | Result |
| -------- | -------- | -------- | ------ |
| M (1000) | C (100)  | Add      | 1000   |
| C (100)  | M (1000) | Subtract | 900    |
| M (1000) | X (10)   | Add      | 1900   |
| X (10)   | C (100)  | Subtract | 1890   |
| C (100)  | I (1)    | Add      | 1990   |
| I (1)    | V (5)    | Subtract | 1989   |
| V (5)    | End      | Add      | 1994   |

Final Answer:

```text
1994
```

---

## Code Logic

```cpp
for (int i = 0; i < s.size(); i++) {
    int curr = roman[s[i]];
    int next = (i + 1 < s.size()) ? roman[s[i + 1]] : 0;

    if (curr < next)
        result -= curr;
    else
        result += curr;
}
```

### Why Does This Work?

When a smaller value appears before a larger value:

```text
IV
IX
XL
XC
CD
CM
```

Roman numerals use subtraction.

The condition:

```cpp
curr < next
```

detects exactly those cases.

---

## Time Complexity

```text
O(N)
```

We visit each character once.

---

## Space Complexity

```text
O(1)
```

The Roman numeral map always contains only 7 symbols.

---

## Key Learning

* Hash Maps (`unordered_map`)
* String Traversal
* Greedy Thinking
* Roman Numeral Rules
* Conditional Addition and Subtraction

---

## Result

The algorithm efficiently converts a Roman numeral into its integer value by checking whether each symbol should be added or subtracted based on the value of the next symbol.
