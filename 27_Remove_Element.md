# 27. Remove Element

## Problem Statement

Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in-place.

Return the number of elements `k` that are not equal to `val`.

The first `k` elements of `nums` should contain all elements that are not equal to `val`. The remaining elements beyond `k` are not important.

> You must perform the operation in-place with O(1) extra space.

---

## Example 1

```text
Input: nums = [3,2,2,3]
val = 3

Output: 2

Modified nums = [2,2,_,_]
```

### Explanation

After removing all occurrences of `3`, only two elements remain:

```text
[2,2]
```

---

## Example 2

```text
Input: nums = [0,1,2,2,3,0,4,2]
val = 2

Output: 5

Modified nums = [0,1,4,0,3,_,_,_]
```

### Explanation

The first 5 elements contain all values not equal to `2`.

---

## Approach

### Two Pointer Technique

We maintain:

* `i` → Traverses the entire array.
* `k` → Tracks the position where the next valid element should be placed.

Whenever an element is not equal to `val`:

1. Copy it to index `k`.
2. Increment `k`.

At the end:

* The first `k` elements contain all valid numbers.
* `k` is the required answer.

---

## Code

```cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int k = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
```

---

## Dry Run

### Input

```text
nums = [3,2,2,3]
val = 3
```

| i | nums[i] | Action      | k |
| - | ------- | ----------- | - |
| 0 | 3       | Skip        | 0 |
| 1 | 2       | nums[0] = 2 | 1 |
| 2 | 2       | nums[1] = 2 | 2 |
| 3 | 3       | Skip        | 2 |

Final Array:

```text
[2,2,_,_]
```

Return:

```text
2
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

The array is traversed exactly once.

### Space Complexity

```text
O(1)
```

No extra data structures are used.

---

## Why This Works

The pointer `k` always points to the next available position for a valid element.

By overwriting unwanted values while traversing:

* No extra memory is required.
* Relative order of valid elements is preserved.
* The solution satisfies the in-place requirement.

---

## Key Concepts

* Arrays
* Two Pointers
* In-Place Modification
* Linear Traversal

---

## Tags

`Array` `Two Pointers` `Easy`

---

## LeetCode

**Problem #27 – Remove Element**

### Stats

* Difficulty: Easy
* Acceptance Rate: 62.0%
* Topics: Array, Two Pointers

### Learning Outcome

This problem is a classic introduction to the **two-pointer technique**, a pattern frequently used in array manipulation and interview questions.
