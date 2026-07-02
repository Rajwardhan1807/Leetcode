# 80. Remove Duplicates from Sorted Array II

## 🟡 Difficulty
Medium

## 📝 Problem Statement

Given a sorted array `nums`, remove duplicates **in-place** so that each unique element appears **at most twice**.

Return the number of remaining elements `k`, with the first `k` elements containing the modified array.

The solution must use **O(1)** extra space.

---

## 💡 Approach

Since the array is sorted, duplicate elements appear consecutively.

Use **two pointers**:

- `r` traverses the array.
- `l` writes the valid elements.

For each group of identical numbers:

1. Count how many times the number appears.
2. Copy it into the array **at most two times**.
3. Move to the next distinct number.

Finally, `l` represents the size of the modified array.

---

## 🧠 Algorithm

1. Initialize:
   - `l = 0`
   - `r = 0`
2. While `r` is within the array:
   - Count the frequency of the current number.
   - Keep only `min(2, count)` copies.
   - Write those copies starting from index `l`.
   - Move `r` to the next distinct element.
3. Return `l`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## 🛠️ Concepts Used

- Two Pointers
- Array Traversal
- In-place Modification

---

## 🚀 Key Insight

Because the array is already sorted, all duplicates are adjacent.

Instead of checking every previous element, process one group of equal values at a time and copy only the first **two occurrences**.

This keeps the algorithm linear while using constant extra space.

---

## 📌 Example

**Input**

```text
nums = [1,1,1,2,2,3]
```

**Processing**

```
1 appears 3 times → Keep 2
2 appears 2 times → Keep 2
3 appears 1 time  → Keep 1
```

**Modified Array**

```text
[1,1,2,2,3]
```

**Output**

```text
k = 5
```

---

## ✅ Solution Highlights

- Uses two pointers for in-place modification.
- Processes each group of duplicates only once.
- Keeps at most two occurrences of every element.
- Preserves the original sorted order.
- Runs in linear time with constant extra space.