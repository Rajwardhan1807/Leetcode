# 11. Container With Most Water

## Problem Statement

You are given an integer array `height` of length `n`. There are `n` vertical lines drawn such that the two endpoints of the `iᵗʰ` line are `(i, 0)` and `(i, height[i])`.

Find two lines that together with the x-axis form a container that can store the maximum amount of water.

Return the maximum amount of water a container can store.

> Note: You may not slant the container.

---

## Example 1

```text
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
```

### Visualization

The maximum area is formed between:

* Height = 8 at index 1
* Height = 7 at index 8

```text
Width = 8 - 1 = 7
Height = min(8, 7) = 7

Area = 7 × 7 = 49
```

---

## Example 2

```text
Input: height = [1,1]
Output: 1
```

---

## Approach

### Two Pointer Technique

Using brute force would require checking every pair of lines:

```text
O(N²)
```

Instead, we can optimize using two pointers.

### Idea

1. Start with:

   * `left = 0`
   * `right = n - 1`

2. Calculate:

   * Width = `right - left`
   * Height = `min(height[left], height[right])`
   * Area = `width × height`

3. Update the maximum area.

4. Move the pointer with the smaller height:

   * A taller line may increase the area.
   * Keeping the smaller line can never produce a larger area because width is already decreasing.

5. Continue until both pointers meet.

---

## Code

```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;

        int maxWater = 0;

        while (left < right) {

            int w = right - left;
            int h = min(height[left], height[right]);

            int area = w * h;

            maxWater = max(maxWater, area);

            if (height[left] < height[right]) {
                left++;
            }
            else if (height[right] < height[left]) {
                right--;
            }
            else {
                left++;
                right--;
            }
        }

        return maxWater;
    }
};
```

---

## Dry Run

### Input

```text
height = [1,8,6,2,5,4,8,3,7]
```

| Left | Right | Width | Height | Area |
| ---- | ----- | ----- | ------ | ---- |
| 0    | 8     | 8     | 1      | 8    |
| 1    | 8     | 7     | 7      | 49   |
| 1    | 7     | 6     | 3      | 18   |
| 1    | 6     | 5     | 8      | 40   |
| ...  | ...   | ...   | ...    | ...  |

Maximum Area:

```text
49
```

---

## Complexity Analysis

### Time Complexity

```text
O(N)
```

Each pointer moves at most `n` times.

### Space Complexity

```text
O(1)
```

No extra data structures are used.

---

## Why Two Pointers Work?

Suppose:

```text
height[left] < height[right]
```

The area is limited by `height[left]`.

Moving `right` inward would only reduce width while still being limited by the shorter line.

Therefore, the only chance of finding a larger area is to move `left` and search for a taller line.

This greedy observation makes the solution optimal.

---

## Key Concepts

* Two Pointers
* Greedy Strategy
* Array Traversal
* Optimization from O(N²) → O(N)

---

## Tags

`Array` `Two Pointers` `Greedy`

---

## LeetCode

**Problem #11 – Container With Most Water**
