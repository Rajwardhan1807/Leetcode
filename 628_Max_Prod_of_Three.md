# 628. Maximum Product of Three Numbers

## 📌 Problem

Given an integer array `nums`, find **three numbers** whose product is maximum and return the maximum product.

**LeetCode:** https://leetcode.com/problems/maximum-product-of-three-numbers/

---

## 💡 Approach

The maximum product of three numbers can come from two possible cases:

### Case 1:
Three largest positive numbers.

Example:

```text
[1,2,3,4]

4 × 3 × 2 = 24
```

### Case 2:
Two smallest negative numbers and the largest positive number.

Example:

```text
[-10,-10,5,2]

(-10) × (-10) × 5 = 500
```

Since two negative numbers make a positive product, we need to check both possibilities.

---

## 🚀 Algorithm

1. Sort the array.
2. Find the size of the array `n`.
3. Calculate:

### Option 1:
Product of two smallest numbers and the largest number:

```text
nums[0] * nums[1] * nums[n-1]
```

### Option 2:
Product of three largest numbers:

```text
nums[n-1] * nums[n-2] * nums[n-3]
```

4. Return the maximum of both options.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        int n = nums.size();

        int opt1 = nums[0] * nums[1] * nums[n-1];

        int opt2 = nums[n-1] * nums[n-2] * nums[n-3];

        return max(opt1, opt2);
    }
};
```

---

## 🧪 Example Walkthrough

### Example 1

**Input**

```text
nums = [1,2,3]
```

Sorted array:

```text
[1,2,3]
```

Option 1:

```text
1 × 2 × 3 = 6
```

Option 2:

```text
3 × 2 × 1 = 6
```

Output:

```text
6
```

---

### Example 2

**Input**

```text
nums = [1,2,3,4]
```

Sorted:

```text
[1,2,3,4]
```

Largest three numbers:

```text
4 × 3 × 2 = 24
```

Output:

```text
24
```

---

### Example 3

**Input**

```text
nums = [-1,-2,-3]
```

Sorted:

```text
[-3,-2,-1]
```

Option 1:

```text
(-3) × (-2) × (-1)
= -6
```

Option 2:

```text
(-1) × (-2) × (-3)
= -6
```

Output:

```text
-6
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n log n)** |
| Space | **O(1)** |

### Explanation:
- Sorting takes `O(n log n)` time.
- No extra data structure is used.

---

## 🔑 Key Concepts

- Sorting
- Greedy Approach
- Array Manipulation
- Handling Negative Numbers

---

## 🎯 Takeaway

For maximum product problems, always consider the effect of negative numbers.  
The answer can come from:

1. The three largest numbers.
2. The two smallest negative numbers with the largest number.

Checking both cases gives the correct maximum product.