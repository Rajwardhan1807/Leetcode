# 55. Jump Game

## Problem Statement

You are given an integer array `nums`, where each element represents the **maximum jump length** from that position.

Starting at index `0`, determine whether you can reach the **last index**.

Return:

* `true` if you can reach the last index.
* `false` otherwise.

---

## Example 1

```text
Input:
nums = [2,3,1,1,4]

Output:
true
```

**Explanation**

```text
Start at index 0.

Jump to index 1.

From index 1, jump directly to the last index.
```

---

## Example 2

```text
Input:
nums = [3,2,1,0,4]

Output:
false
```

**Explanation**

```text
No matter how you jump, you'll eventually reach index 3.

nums[3] = 0

You cannot move any further, so reaching the last index is impossible.
```

---

# Approach

### Greedy (Work Backwards)

Instead of jumping forward, start from the **last index**, treating it as the current goal.

Steps:

1. Set `goal` as the last index.
2. Traverse the array from right to left.
3. If the current index can reach the goal (`i + nums[i] >= goal`):

   * Update `goal = i`.
4. After the traversal:

   * If `goal == 0`, the first index can reach the end.
   * Otherwise, it cannot.

---

# Why This Works

Suppose:

```text
nums = [2,3,1,1,4]
```

Initially:

```text
Goal = 4
```

Traverse backwards:

```text
Index 3:

3 + nums[3] = 3 + 1 = 4

Can reach goal.

Goal = 3
```

```text
Index 2:

2 + 1 = 3

Can reach goal.

Goal = 2
```

```text
Index 1:

1 + 3 = 4

Can reach goal.

Goal = 1
```

```text
Index 0:

0 + 2 = 2

Can reach goal.

Goal = 0
```

Since the goal becomes **0**, the answer is **true**.

---

# Code

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {

        int goal = nums.size() - 1;

        for(int i = goal - 1; i >= 0; i--) {

            if(i + nums[i] >= goal) {
                goal = i;
            }
        }

        return goal == 0;
    }
};
```

---

# Dry Run

### Input

```text
nums = [2,3,1,1,4]
```

Initial goal:

```text
Goal = 4
```

| Index | nums[i] | Can Reach Goal? | New Goal |
| ----: | ------: | :-------------: | -------: |
|     3 |       1 |       Yes       |        3 |
|     2 |       1 |       Yes       |        2 |
|     1 |       3 |       Yes       |        1 |
|     0 |       2 |       Yes       |        0 |

Final:

```text
Goal = 0
```

Return:

```text
true
```

---

# Complexity Analysis

### Time Complexity

```text
O(n)
```

The array is traversed exactly once.

---

### Space Complexity

```text
O(1)
```

Only one extra variable (`goal`) is used.

---

# Key Concepts

* Greedy Algorithm
* Backward Traversal
* Array
* Reachability

---

# LeetCode

**Problem #55 – Jump Game**

### Stats

* **Difficulty:** Medium
* **Runtime:** **0 ms**
* **Topics:** Array, Greedy

### Learning Outcome

This problem teaches a powerful **greedy strategy**. Instead of trying every possible jump, we work **backwards** from the last index and keep updating the leftmost position that can reach the current goal. If the goal finally becomes index `0`, reaching the end is possible. This approach achieves the optimal **O(n)** time and **O(1)** space complexity.
