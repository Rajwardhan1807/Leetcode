# 16. 3Sum Closest

## Problem Statement

Given an integer array `nums` and an integer `target`, find three integers whose sum is **closest** to the target.

Return the sum of the three integers.

You may assume that each input has exactly one solution.

---

## Example 1

```text id="w4jzkr"
Input: nums = [-1,2,1,-4], target = 1

Output: 2
```

**Explanation**

```text id="5whwpa"
(-1 + 2 + 1) = 2
```

The sum `2` is the closest to the target `1`.

---

## Example 2

```text id="w6q9lu"
Input: nums = [0,0,0], target = 1

Output: 0
```

---

## Approach

### Sorting + Two Pointers

1. Sort the array.
2. Fix one element at a time.
3. Use two pointers:

   * `left` starts just after the fixed element.
   * `right` starts from the end.
4. Compute the current sum.
5. If this sum is closer to the target than the previous best, update the answer.
6. Move:

   * `left++` if the sum is too small.
   * `right--` if the sum is too large.
7. If the sum equals the target, return immediately since it is the closest possible.

---

## Why This Works

Sorting allows us to adjust the sum efficiently.

If the current sum is:

* **Less than target** → move `left` right to increase the sum.
* **Greater than target** → move `right` left to decrease the sum.

This checks all possible closest sums in **O(N²)** time.

---

## Code

```cpp id="k9fj1m"
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - result))
                    result = sum;

                if (sum < target)
                    left++;
                else if (sum > target)
                    right--;
                else
                    return sum;
            }
        }

        return result;
    }
};
```

---

## Dry Run

### Input

```text id="1dcjdo"
nums = [-1,2,1,-4]
target = 1
```

After sorting:

```text id="gpb0w6"
[-4,-1,1,2]
```

Initial answer:

```text id="16dc4k"
-4 + (-1) + 1 = -4
```

Fix `-4`:

```text id="6b8bqg"
left = -1
right = 2
```

Current sum:

```text id="wmqv9m"
-4 + (-1) + 2 = -3
```

Move `left`.

Next sum:

```text id="kbrlnx"
-4 + 1 + 2 = -1
```

Move `left`.

Fix `-1`:

```text id="6g78x5"
-1 + 1 + 2 = 2
```

Difference from target:

```text id="e8krp3"
|2 - 1| = 1
```

This is the closest sum.

Final Answer:

```text id="l6f0cv"
2
```

---

## Complexity Analysis

### Time Complexity

```text id="pprfh5"
O(N²)
```

* Sorting takes **O(N log N)**.
* Two-pointer traversal takes **O(N²)**.

Overall complexity is **O(N²)**.

### Space Complexity

```text id="mnfr4s"
O(1)
```

Only a few extra variables are used.

---

## Key Concepts

* Sorting
* Two Pointers
* Greedy Update
* Arrays

---

## LeetCode

**Problem #16 – 3Sum Closest**

### Stats

* **Difficulty:** Medium
* **Acceptance Rate:** 48.8%
* **Topics:** Array, Two Pointers, Sorting

### Learning Outcome

This problem builds on **3Sum** by using the same **Sorting + Two Pointers** technique, but instead of finding all valid triplets, it continuously tracks the sum with the smallest difference from the target.
