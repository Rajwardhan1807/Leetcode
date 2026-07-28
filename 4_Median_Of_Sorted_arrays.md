# LeetCode 4 - Median of Two Sorted Arrays

## Problem Statement

Given two sorted arrays `nums1` and `nums2` of sizes `m` and `n` respectively, return the median of the two sorted arrays.

The overall runtime complexity should be:

```text
O(log(m+n))
```

---

## Examples

### Example 1

```text
Input:
nums1 = [1,3]
nums2 = [2]

Merged Array:
[1,2,3]

Median:
2

Output:
2.00000
```

---

### Example 2

```text
Input:
nums1 = [1,2]
nums2 = [3,4]

Merged Array:
[1,2,3,4]

Median:
(2 + 3) / 2 = 2.5

Output:
2.50000
```

---

# Approach

The brute force approach is to merge both arrays and find the middle element, but that takes:

```text
O(m+n)
```

The required complexity is:

```text
O(log(m+n))
```

so we use **Binary Search**.

---

## Binary Search Partition Approach

The idea is to divide both arrays into two parts:

```
nums1: [left part | right part]
nums2: [left part | right part]
```

The partition should satisfy:

```
max(left side) <= min(right side)
```

This means all elements on the left side are smaller than all elements on the right side.

### Steps:

1. Always perform binary search on the smaller array.

2. Find partition positions:

   * `cut1` in `nums1`
   * `cut2` in `nums2`

3. Calculate boundary values:

```
left1  = nums1[cut1 - 1]
right1 = nums1[cut1]

left2  = nums2[cut2 - 1]
right2 = nums2[cut2]
```

4. Check if the partition is valid:

```
left1 <= right2 && left2 <= right1
```

5. If valid:

   * For odd total length:

```
median = max(left1, left2)
```

* For even total length:

```
median = (max(left1,left2) + min(right1,right2)) / 2
```

---

# Dry Run

### Input

```text
nums1 = [1,3]
nums2 = [2]
```

Total elements:

```
3
```

Partition:

```
nums1: [1 | 3]
nums2: [2 | ]
```

Left side:

```
[1,2]
```

Right side:

```
[3]
```

Median:

```
max(1,2) = 2
```

Output:

```text
2.00000
```

---

# C++ Solution

```cpp
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int m = nums1.size();
        int n = nums2.size();

        int low = 0;
        int high = m;

        while(low <= high) {

            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int right1 = (cut1 == m) ? INT_MAX : nums1[cut1];

            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int right2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if(left1 <= right2 && left2 <= right1) {

                if((m+n) % 2 == 0) {
                    return (max(left1,left2) + min(right1,right2)) / 2.0;
                }
                else {
                    return max(left1,left2);
                }
            }

            else if(left1 > right2) {
                high = cut1 - 1;
            }

            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
```

---

# Complexity Analysis

## Time Complexity

```text
O(log(min(m,n)))
```

Binary search is performed only on the smaller array.

## Space Complexity

```text
O(1)
```

No additional data structures are used.

---

# Concepts Used

* Binary Search
* Divide and Conquer
* Array Partitioning
* Mathematical Optimization

---

# LeetCode Details

* **Problem:** 4. Median of Two Sorted Arrays
* **Difficulty:** Hard
* **Language:** C++
* **Approach:** Binary Search Partition
* **Time Complexity:** O(log(min(m,n)))
* **Space Complexity:** O(1)

---

This problem is one of the most important binary search problems because it teaches how binary search can be applied on the answer space rather than directly searching for an element.
