# 69. Sqrt(x)

## Problem Statement

Given a non-negative integer `x`, return the square root of `x` rounded down to the nearest integer.

The returned integer should be non-negative as well.

> You must not use any built-in exponent function or operator such as `pow(x, 0.5)` or `sqrt(x)`.

---

## Examples

### Example 1

**Input**
```text
x = 4
```

**Output**
```text
2
```

---

### Example 2

**Input**
```text
x = 8
```

**Output**
```text
2
```

**Explanation**

The square root of 8 is approximately 2.82842, and since we round down, the answer is 2.

---

## Approach

This solution uses **Binary Search**.

### Algorithm

1. Handle edge cases (`x = 0` and `x = 1`).
2. Set `low = 1` and `high = x`.
3. Find the middle element.
4. Compute `mid * mid`.
5. If `mid² == x`, return `mid`.
6. If `mid² < x`, store `mid` as the current answer and search the right half.
7. Otherwise, search the left half.
8. Return the stored answer.

---

## Solution (C++)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;

        int low = 1, high = x;
        int ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;

            if (square == x)
                return mid;
            else if (square < x) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

---

## Dry Run

For `x = 8`

| Low | High | Mid | Mid² | Action |
|-----:|------:|----:|------:|--------|
| 1 | 8 | 4 | 16 | Search Left |
| 1 | 3 | 2 | 4 | Store Answer = 2, Search Right |
| 3 | 3 | 3 | 9 | Search Left |

Final Answer:

```text
2
```

---

## Complexity Analysis

- **Time Complexity:** `O(log x)`
- **Space Complexity:** `O(1)`

---

## Key Points

- Uses **Binary Search** for efficient computation.
- Avoids built-in functions like `sqrt()` and `pow()`.
- Uses `long long` to prevent integer overflow while computing `mid * mid`.
- Returns the floor value of the square root.

---

## LeetCode

**Problem:** 69. Sqrt(x)