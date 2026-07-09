# 🔍 LeetCode 35 - Search Insert Position

## 📌 Problem

Given a sorted array of distinct integers `nums` and a target value, return:

- The index if the target exists.
- Otherwise, the index where it should be inserted to maintain sorted order.

The solution must run in **O(log n)** time.

---

## 💡 Approach

This solution uses **Binary Search**.

1. Initialize two pointers:
   - `left = 0`
   - `right = n - 1`
2. Find the middle element.
3. If the middle element equals the target, return its index.
4. If the target is smaller, search the left half.
5. If the target is larger, search the right half.
6. If the target is not found, `left` will point to the correct insertion position.

---

## ✅ Algorithm

1. Set `left = 0` and `right = nums.size() - 1`.
2. While `left <= right`:
   - Compute `mid`.
   - If `nums[mid] == target`, return `mid`.
   - If `nums[mid] > target`, move `right = mid - 1`.
   - Otherwise, move `left = mid + 1`.
3. Return `left` as the insertion index.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(log n)`
  - Binary search halves the search space in every iteration.

- **Space Complexity:** `O(1)`
  - Uses only a few extra variables.

---

## 🧠 Key Concepts

- Binary Search
- Sorted Array
- Divide and Conquer

---

## 🚀 Example

### Input

```text
nums = [1,3,5,6]
target = 5
```

### Output

```text
2
```

---

### Input

```text
nums = [1,3,5,6]
target = 2
```

### Output

```text
1
```

---

### Input

```text
nums = [1,3,5,6]
target = 7
```

### Output

```text
4
```

---

## 📖 What I Learned

- How binary search efficiently finds an element in a sorted array.
- If the target isn't found, the `left` pointer naturally ends at the correct insertion position.
- Binary search is the optimal solution for sorted array lookup problems.

---

## 🏷️ Tags

`Binary Search` `Array` `Divide and Conquer`