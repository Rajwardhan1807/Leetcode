# 8. String to Integer (atoi)

## Problem Statement

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer.

The conversion follows these rules:

- Ignore leading whitespace.
- Check for an optional '+' or '-' sign.
- Read digits until a non-digit character is encountered.
- If no digits are found, return `0`.
- If the number exceeds the 32-bit signed integer range, return:
  - `INT_MAX (2147483647)`
  - `INT_MIN (-2147483648)`

---

## Example 1

```text
Input: s = "42"
Output: 42
```

## Example 2

```text
Input: s = "   -042"
Output: -42
```

## Example 3

```text
Input: s = "1337c0d3"
Output: 1337
```

---

## Approach

### String Parsing

1. Skip leading spaces.
2. Determine the sign.
3. Read digits and build the number.
4. Stop when a non-digit character is found.
5. Handle overflow by returning `INT_MAX` or `INT_MIN`.

### Example

```text
Input: "   -42"

Skip spaces → "-42"
Read sign → negative
Read digits → 42

Result = -42
```

---

## Code

```cpp
class Solution {
public:
    int myAtoi(string s) {

        if (s.empty()) {
            return 0;
        }

        int i = 0;
        int n = s.length();

        const long long MAX_INT = INT_MAX;
        const long long MIN_INT = INT_MIN;

        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            result = result * 10 + digit;

            if (sign * result > MAX_INT) {
                return INT_MAX;
            }

            if (sign * result < MIN_INT) {
                return INT_MIN;
            }

            i++;
        }

        return sign * result;
    }
};
```

---

## Complexity Analysis

### Time Complexity

`O(N)`

### Space Complexity

`O(1)`

---

## Key Concepts

- String Parsing
- Simulation
- Overflow Handling
- Character Processing

---

## LeetCode

**Problem #8 – String to Integer (atoi)**

### Learning Outcome

This problem teaches careful string parsing, handling signs, managing invalid characters, and detecting integer overflow.