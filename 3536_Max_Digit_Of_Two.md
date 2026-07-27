# LeetCode 3536 - Maximum Product of Two Digits

## Problem Statement

Given a positive integer `n`, return the maximum product of any two digits in `n`.

### Note:

* You may choose the same digit twice only if it appears more than once in the number.

---

## Examples

### Example 1

```
Input: n = 31

Digits: [3, 1]

Possible Products:
3 × 1 = 3

Output:
3
```

### Example 2

```
Input: n = 22

Digits: [2, 2]

Possible Products:
2 × 2 = 4

Output:
4
```

### Example 3

```
Input: n = 124

Digits: [1, 2, 4]

Possible Products:
1 × 2 = 2
1 × 4 = 4
2 × 4 = 8

Output:
8
```

---

# Approach

To maximize the product of two digits, we only need to find the two largest digits present in the number.

### Algorithm:

1. Extract each digit using modulo (`n % 10`).
2. Maintain:

   * `first` → largest digit found.
   * `second` → second largest digit found.
3. Update these values while traversing all digits.
4. Return:

```
first * second
```

---

# Dry Run

### Input:

```
n = 124
```

### Processing:

| Digit | First Largest | Second Largest |
| ----- | ------------- | -------------- |
| 4     | 4             | 0              |
| 2     | 4             | 2              |
| 1     | 4             | 2              |

Result:

```
4 × 2 = 8
```

---

# C++ Solution

```cpp
class Solution {
public:
    int maxProduct(int n) {
        int first = 0;
        int second = 0;

        while(n > 0) {
            int digit = n % 10;
            n /= 10;

            if(digit > first) {
                second = first;
                first = digit;
            }
            else if(digit > second) {
                second = digit;
            }
        }

        return first * second;
    }
};
```

---

# Complexity Analysis

### Time Complexity

```
O(log10(n))
```

Each digit of the number is processed once.

### Space Complexity

```
O(1)
```

Only two variables are used.

---

# Concepts Used

* Number manipulation
* Digit extraction
* Greedy approach
* Maximum tracking

---

# LeetCode Details

* Problem: 3536. Maximum Product of Two Digits
* Difficulty: Easy
* Language: C++
* Runtime: 0 ms
* Space Complexity: O(1)

---

If this solution helped you, consider starring the repository.

