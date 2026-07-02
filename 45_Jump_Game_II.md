# 45. Jump Game II

## 🟡 Difficulty
Medium

## 📝 Problem Statement

Given an array `nums` where each element represents the maximum jump length from that position, return the **minimum number of jumps** required to reach the last index.

It is guaranteed that the last index is reachable.

---

## 💡 Approach

Use a **Greedy + BFS Level Traversal** approach.

Think of each jump as one **level** in BFS.

- `l` and `r` represent the current range of indices that can be reached using the current number of jumps.
- Iterate through every index in this range and calculate the farthest position reachable.
- Once the entire range has been explored, increase the jump count and move to the next range.
- Continue until the last index is included in the current range.

---

## 🧠 Algorithm

1. Initialize:
   - `l = 0`
   - `r = 0`
   - `jumps = 0`
2. While the current range doesn't include the last index:
   - Find the farthest index reachable from every position between `l` and `r`.
   - Update the next range:
     - `l = r + 1`
     - `r = farthest`
   - Increment the jump count.
3. Return the total number of jumps.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 🛠️ Concepts Used

- Greedy Algorithm
- BFS Level Traversal
- Sliding Window
- Array Traversal

---

## 🚀 Key Insight

Instead of deciding the best jump from every position individually, process **all positions reachable with the current jump**.

Among them, choose the **farthest position** that can be reached with the next jump.

This guarantees the minimum number of jumps while visiting each element only once.

---

## 📌 Example

**Input**

```text
nums = [2,3,1,1,4]
```

**Process**

```
Jump 0:
Reachable indices = [0]
Farthest = 2

Jump 1:
Reachable indices = [1,2]
Farthest = 4

Reached last index.
```

**Output**

```text
2
```

---

## ✅ Solution Highlights

- Linear time greedy solution.
- Uses constant extra space.
- Processes each index only once.
- Treats each jump as a BFS level.
- Guaranteed to find the minimum number of jumps.