# 88. Merge Sorted Array

## Problem Statement

You are given two sorted integer arrays:

* `nums1` of size `m + n`, where the first `m` elements are valid and the last `n` elements are extra space.
* `nums2` of size `n`.

Merge `nums2` into `nums1` so that the final array is sorted in **non-decreasing order**.

The merge must be done **in-place**, without returning a new array.

---

## Example 1

```text
Input:
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3

Output:
[1,2,2,3,5,6]
```

---

## Example 2

```text
Input:
nums1 = [1]
m = 1

nums2 = []
n = 0

Output:
[1]
```

---

## Example 3

```text
Input:
nums1 = [0]
m = 0

nums2 = [1]
n = 1

Output:
[1]
```

---

# Approach

### Three Pointers (Merge from the End)

Instead of merging from the front (which would overwrite elements), start filling `nums1` **from the last index**.

Use three pointers:

* `m - 1` → Last valid element of `nums1`
* `n - 1` → Last element of `nums2`
* `last = m + n - 1` → Last position in `nums1`

Steps:

1. Compare the last elements of both arrays.
2. Place the larger one at `nums1[last]`.
3. Move the corresponding pointer backward.
4. Decrease `last`.
5. If elements remain in `nums2`, copy them into `nums1`.

---

# Why This Works

Suppose:

```text
nums1 = [1,2,3,0,0,0]
nums2 = [2,5,6]
```

Initially:

```text
nums1 : [1 2 3 0 0 0]
                 ↑
               last

nums2 : [2 5 6]
             ↑
```

Compare:

```text
3 vs 6
```

Place **6** at the end.

```text
[1 2 3 0 0 6]
```

Next:

```text
3 vs 5
```

Place **5**.

```text
[1 2 3 0 5 6]
```

Next:

```text
3 vs 2
```

Place **3**.

```text
[1 2 3 3 5 6]
```

Continue until one array is exhausted.

Final result:

```text
[1 2 2 3 5 6]
```

---

# Code

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int last = m + n - 1;

        while(m > 0 && n > 0) {

            if(nums1[m - 1] > nums2[n - 1]) {
                nums1[last] = nums1[m - 1];
                m--;
            }
            else {
                nums1[last] = nums2[n - 1];
                n--;
            }

            last--;
        }

        // Copy remaining elements of nums2
        while(n > 0) {
            nums1[last] = nums2[n - 1];
            n--;
            last--;
        }
    }
};
```

---

# Dry Run

### Input

```text
nums1 = [1,2,3,0,0,0]
m = 3

nums2 = [2,5,6]
n = 3
```

### Step 1

```text
3 vs 6

Place 6

[1,2,3,0,0,6]
```

### Step 2

```text
3 vs 5

Place 5

[1,2,3,0,5,6]
```

### Step 3

```text
3 vs 2

Place 3

[1,2,3,3,5,6]
```

### Step 4

```text
2 vs 2

Place 2 (from nums2)

[1,2,2,3,5,6]
```

`nums2` is exhausted.

Final Answer:

```text
[1,2,2,3,5,6]
```

---

# Complexity Analysis

### Time Complexity

```text
O(m + n)
```

Each element is processed exactly once.

---

### Space Complexity

```text
O(1)
```

The merge is performed **in-place**, using only a few extra variables.

---

# Key Concepts

* Two Pointers
* Three Pointer Technique
* In-place Merging
* Sorted Arrays

---

# LeetCode

**Problem #88 – Merge Sorted Array**

### Stats

* **Difficulty:** Easy
* **Runtime:** **0 ms**
* **Topics:** Array, Two Pointers, Sorting

### Learning Outcome

This problem teaches the **reverse merge technique**, where merging starts from the end of the destination array. This avoids overwriting existing elements and achieves the optimal **O(m + n)** time complexity with **O(1)** extra space.
