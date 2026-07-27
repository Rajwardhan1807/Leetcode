# 1464. Maximum Product of Two Elements in an Array

## 📌 Problem

Given an integer array `nums`, choose **two different indices** `i` and `j`.

Return the maximum value of:

\[
(nums[i]-1) \times (nums[j]-1)
\]

**LeetCode:** https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

---

## 💡 Approach

To maximize the expression:

```text
(nums[i] - 1) * (nums[j] - 1)
```

we simply need the **two largest numbers** in the array.

Instead of sorting the array (O(n log n)), we can find the largest and second-largest elements in **one traversal**.

### Steps

- Maintain two variables:
  - `first` → Largest element.
  - `second` → Second largest element.
- Traverse the array once.
- Update `first` and `second` whenever a larger number is found.
- Return:

```text
(first - 1) * (second - 1)
```

---

## 🚀 Algorithm

1. Initialize:
   - `first = 0`
   - `second = 0`
2. Traverse every element in `nums`.
3. If the current number is greater than `first`:
   - Move `first` to `second`.
   - Update `first`.
4. Otherwise, if it is greater than `second`, update `second`.
5. Return:

```text
(first - 1) * (second - 1)
```

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0, second = 0;

        for (int num : nums) {
            if (num > first) {
                second = first;
                first = num;
            }
            else if (num > second) {
                second = num;
            }
        }

        return (first - 1) * (second - 1);
    }
};
```

---

## 🧪 Example Walkthrough

### Example 1

**Input**

```text
nums = [3,4,5,2]
```

Traversal:

| Current | First | Second |
|--------:|------:|-------:|
|3|3|0|
|4|4|3|
|5|5|4|
|2|5|4|

Result:

```text
(5-1) × (4-1)
= 4 × 3
= 12
```

Output:

```text
12
```

---

### Example 2

**Input**

```text
nums = [1,5,4,5]
```

Largest numbers:

```text
5 and 5
```

Result:

```text
(5-1) × (5-1)
= 4 × 4
= 16
```

Output:

```text
16
```

---

### Example 3

**Input**

```text
nums = [3,7]
```

Largest numbers:

```text
7 and 3
```

Result:

```text
(7-1) × (3-1)
= 6 × 2
= 12
```

Output:

```text
12
```

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| **Time** | **O(n)** |
| **Space** | **O(1)** |

- The array is traversed only once.
- No extra data structures are used.

---

## 🔑 Key Concepts

- Array Traversal
- Greedy
- Tracking Largest & Second Largest Elements
- Optimization without Sorting

---

## 🎯 Takeaway

Instead of sorting the array, keep track of the **largest** and **second-largest** numbers while traversing the array once. This achieves the optimal **O(n)** time complexity with **O(1)** extra space.