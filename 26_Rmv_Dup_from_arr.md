# 26. Remove Duplicates from Sorted Array

## Problem Statement

Given a sorted integer array `nums` in non-decreasing order, remove duplicates in-place such that each unique element appears only once.

Return the number of unique elements `k`.

The first `k` elements of `nums` should contain the unique elements in their original sorted order. The remaining elements can be ignored.

> You must solve the problem using O(1) extra memory.

---

## Example 1

```text
Input: nums = [1,1,2]

Output: 2
nums = [1,2,_]
```

### Explanation

After removing duplicates:

```text
[1,2]
```

Number of unique elements:

```text
k = 2
```

---

## Example 2

```text
Input: nums = [0,0,1,1,1,2,2,3,3,4]

Output: 5
nums = [0,1,2,3,4,_,_,_,_,_]
```

### Explanation

Unique elements are:

```text
[0,1,2,3,4]
```

Number of unique elements:

```text
k = 5
```

---

## Approach

### Two Pointer Technique

Since the array is already sorted:

* Duplicate values always appear consecutively.
* We can use two pointers:

  * `r` → scans the array.
  * `l` → points to the position where the next unique element should be placed.

Whenever a new unique element is found:

1. Place it at index `l`.
2. Increment `l`.

At the end:

* The first `l` elements are unique.
* `l` is the answer.

---

## Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size() == 0) {
            return 0;
        }

        int l = 1;

        for(int r = 1; r < nums.size(); r++) {

            if(nums[r] != nums[r - 1]) {
                nums[l] = nums[r];
                l++;
            }
        }

        return l;
    }
};
```

---

## Dry Run

### Input

```text
nums = [1,1,2]
```

### Initial State

```text
l = 1
```

| r | nums[r] | Compare | Action      | l |
| - | ------- | ------- | ----------- | - |
| 1 | 1       | 1 == 1  | Skip        | 1 |
| 2 | 2       | 2 != 1  | nums[1] = 2 | 2 |

Final array:

```text
[1,2,_]
```

Return:

```text
2
```

---

## Dry Run 2

### Input

```text
nums = [0,0,1,1,1,2,2,3,3,4]
```

Unique elements copied:

```text
0 → 1 → 2 → 3 → 4
```

Result:

```text
[0,1,2,3,4,_,_,_,_,_]
```

Return:

```text
5
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

No extra array or data structure is used.

---

## Why This Works

Because the array is sorted:

```text
Duplicate values always appear next to each other.
```

Comparing the current element with the previous one is sufficient to detect duplicates.

The `l` pointer ensures that all unique elements are compacted at the beginning of the array while maintaining sorted order.

---

## Key Concepts

* Arrays
* Two Pointers
* In-Place Modification
* Sorted Arrays

---

## Tags

`Array` `Two Pointers` `Easy`

---

## LeetCode

**Problem #26 – Remove Duplicates from Sorted Array**

### Stats

* Difficulty: Easy
* Acceptance Rate: 63.1%
* Topics: Array, Two Pointers

### Learning Outcome

This is one of the most important introductory **Two Pointer** problems and forms the basis for many advanced array manipulation questions.
