# 7. Reverse Integer

## Problem Statement

Given a signed 32-bit integer `x`, return `x` with its digits reversed.

If reversing `x` causes the value to go outside the signed 32-bit integer range:

```text
[-2³¹, 2³¹ - 1]
```

return `0`.

> Assume the environment does not allow storing 64-bit integers.

---

## Example 1

```text
Input: x = 123
Output: 321
```

### Explanation

```text
123 → 321
```

---

## Example 2

```text
Input: x = -123
Output: -321
```

### Explanation

```text
-123 → -321
```

---

## Example 3

```text
Input: x = 120
Output: 21
```

### Explanation

Leading zeros are removed automatically.

```text
120 → 021 → 21
```

---

## Approach

### Mathematical Digit Extraction

We reverse the number digit by digit.

For each iteration:

1. Extract the last digit using:

```cpp
digit = x % 10;
```

2. Remove the last digit:

```cpp
x /= 10;
```

3. Append the digit to the answer:

```cpp
ans = ans * 10 + digit;
```

---

## Overflow Handling

Since we cannot use 64-bit integers, we must check whether multiplying by 10 would overflow before updating the answer.

### Safe Check

```cpp
if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
    return 0;
```

If overflow or underflow is detected, return `0`.

---

## Code

```cpp
class Solution {
public:
    int reverse(int x) {

        int ans = 0;

        while (x != 0) {

            int digit = x % 10;

            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }

            ans = ans * 10 + digit;
            x = x / 10;
        }

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
x = 123
```

| x   | digit | ans  |
| --- | ----- | ---- |
| 123 | 3     | 3    |
| 12  | 2     | 32   |
| 1   | 1     | 321  |
| 0   | -     | Stop |

Output:

```text
321
```

---

## Dry Run 2

### Input

```text
x = -123
```

| x    | digit | ans  |
| ---- | ----- | ---- |
| -123 | -3    | -3   |
| -12  | -2    | -32  |
| -1   | -1    | -321 |

Output:

```text
-321
```

---

## Complexity Analysis

### Time Complexity

```text
O(log₁₀ N)
```

We process each digit exactly once.

---

### Space Complexity

```text
O(1)
```

Only a few integer variables are used.

---

## Why This Works

Each iteration:

* Extracts one digit.
* Removes it from the original number.
* Appends it to the reversed number.

The overflow check guarantees that the final answer remains within the valid 32-bit signed integer range.

---

## Key Concepts

* Math
* Integer Manipulation
* Modulo Operator
* Overflow Detection

---

## Tags

`Math` `Integer` `Simulation` `Medium`

---

## LeetCode

**Problem #7 – Reverse Integer**

### Stats

* Difficulty: Medium
* Acceptance Rate: 32.0%
* Topics: Math

### Learning Outcome

This problem teaches how to manipulate digits mathematically and safely handle integer overflow without using larger data types.
