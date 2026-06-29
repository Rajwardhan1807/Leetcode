# 29. Divide Two Integers

## Problem Statement

Given two integers `dividend` and `divisor`, divide them **without using multiplication (`*`), division (`/`), or modulus (`%`) operators**.

Return the quotient after truncating the decimal part.

If the result overflows the **32-bit signed integer** range, return:

* `INT_MAX` if the result is greater than `2³¹ - 1`
* `INT_MIN` if the result is less than `-2³¹`

---

## Example 1

```text
Input:
dividend = 10
divisor = 3

Output:
3
```

**Explanation**

```text
10 / 3 = 3.333...

After truncating:
3
```

---

## Example 2

```text
Input:
dividend = 7
divisor = -3

Output:
-2
```

---

## Approach

### Bit Manipulation (Repeated Doubling)

Instead of subtracting the divisor one by one, repeatedly **double the divisor** using left shifts until it becomes the largest possible multiple that can still be subtracted.

Steps:

1. Handle the overflow case:

   * `INT_MIN / -1` → `INT_MAX`
2. Convert both numbers to positive (`long long`) using `abs()`.
3. While the dividend is greater than or equal to the divisor:

   * Double the divisor (`sum <<= 1`)
   * Double the count (`count <<= 1`)
   * Keep doubling until the next double exceeds the dividend.
4. Subtract the largest doubled divisor from the dividend.
5. Add the corresponding count to the answer.
6. Apply the correct sign at the end.

---

## Why This Works

Suppose:

```text
dividend = 25
divisor = 3
```

Start with:

```text
sum = 3
count = 1
```

Double repeatedly:

```text
3   -> count = 1
6   -> count = 2
12  -> count = 4
24  -> count = 8
48  -> Too large
```

Subtract:

```text
25 - 24 = 1
```

Answer becomes:

```text
8
```

Since the remaining dividend (1) is smaller than the divisor (3), we're done.

Result:

```text
25 / 3 = 8
```

---

## Code

```cpp
class Solution {
public:
    int divide(int dd, int ds) {

        // Overflow cases
        if (dd == INT_MIN && ds == -1) return INT_MAX;
        if (dd == INT_MIN && ds == 1) return INT_MIN;

        long long dn = abs((long long)dd);
        long long dv = abs((long long)ds);

        int ans = 0;

        while (dn >= dv) {

            long long sum = dv;
            long long count = 1;

            while ((sum << 1) <= dn) {
                sum <<= 1;
                count <<= 1;
            }

            dn -= sum;
            ans += count;
        }

        // Apply sign
        if ((dd < 0) ^ (ds < 0))
            return -ans;

        return ans;
    }
};
```

---

## Dry Run

### Input

```text
dividend = 10
divisor = 3
```

Initially:

```text
Dividend = 10
Divisor  = 3
Answer   = 0
```

### First Iteration

```text
3  -> count = 1
6  -> count = 2
12 -> Too large
```

Subtract:

```text
10 - 6 = 4

Answer = 2
```

### Second Iteration

```text
3 -> count = 1
6 -> Too large
```

Subtract:

```text
4 - 3 = 1

Answer = 3
```

Remaining dividend:

```text
1 < 3
```

Stop.

Final Answer:

```text
3
```

---

## Complexity Analysis

### Time Complexity

```text
O(log² N)
```

* The outer loop runs about **log N** times.
* Inside it, the divisor is doubled using left shifts, which also takes **log N** time.

---

### Space Complexity

```text
O(1)
```

Only a few variables are used.

---

## Key Concepts

* Bit Manipulation (`<<`)
* Left Shift
* Greedy
* Integer Overflow Handling
* Absolute Value
* Efficient Division

---

## LeetCode

**Problem #29 – Divide Two Integers**

### Stats

* **Difficulty:** Medium
* **Runtime:** **0 ms**
* **Topics:** Math, Bit Manipulation

### Learning Outcome

This problem demonstrates how division can be performed efficiently using **bit manipulation**. By repeatedly doubling the divisor with left shifts, we reduce the number of operations from repeated subtraction to a logarithmic approach while carefully handling overflow and negative numbers.
