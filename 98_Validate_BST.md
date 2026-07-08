# 98. Validate Binary Search Tree

## 🟡 Difficulty
Medium

## 📝 Problem Statement

Given the root of a binary tree, determine whether it is a **valid Binary Search Tree (BST)**.

A BST must satisfy:

- Every node in the left subtree is **strictly smaller** than the current node.
- Every node in the right subtree is **strictly greater** than the current node.
- Both left and right subtrees must also be valid BSTs.

Return `true` if the tree is a valid BST; otherwise, return `false`.

---

## 💡 Approach

Use **DFS (Recursion)** while maintaining the **valid range** for every node.

- Initially, the root can have any value (`-∞` to `+∞`).
- For the left child:
  - Maximum allowed value becomes the current node's value.
- For the right child:
  - Minimum allowed value becomes the current node's value.
- If any node violates its valid range, the tree is not a BST.

Using value ranges ensures that every node satisfies the BST property with respect to **all its ancestors**, not just its parent.

---

## 🧠 Algorithm

1. Create a recursive function `isBST(node, minValue, maxValue)`.
2. If the node is `NULL`, return `true`.
3. If the node's value is not within `(minValue, maxValue)`, return `false`.
4. Recursively check:
   - Left subtree with range `(minValue, node->val)`
   - Right subtree with range `(node->val, maxValue)`
5. Return `true` only if both subtrees are valid.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(h)`

Where:
- `n` = Number of nodes
- `h` = Height of the tree (recursive call stack)

---

## 🛠️ Concepts Used

- Binary Search Tree (BST)
- Depth-First Search (DFS)
- Recursion
- Tree Traversal

---

## 🚀 Key Insight

Checking only the immediate parent is **not enough**.

Each node must satisfy the valid range determined by **all its ancestors**.

Passing minimum and maximum allowed values during recursion guarantees every node follows the BST property.

---

## 📌 Example

**Input**

```text
        5
       / \
      1   4
         / \
        3   6
```

**Checking Ranges**

```
5 → (-∞, +∞) ✅

1 → (-∞, 5) ✅

4 → (5, +∞) ❌
```

Since `4` is less than `5` but lies in the right subtree of `5`, the tree is **not** a valid BST.

**Output**

```text
false
```

---

## ✅ Solution Highlights

- Uses recursion with minimum and maximum value limits.
- Correctly validates the BST property across the entire tree.
- Visits each node exactly once.
- Handles edge cases using `LLONG_MIN` and `LLONG_MAX`.
- Efficient linear-time solution.