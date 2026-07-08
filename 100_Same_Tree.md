# 🌳 LeetCode 100 - Same Tree

## 📌 Problem
Given the roots of two binary trees `p` and `q`, determine whether they are identical.

Two binary trees are considered the same if:
- They have the same structure.
- Corresponding nodes contain the same values.

---

## 💡 Approach

This solution uses **Recursive Depth-First Search (DFS)**.

At each recursive call:

1. If both nodes are `NULL`, they are identical → return `true`.
2. If one node is `NULL` and the other isn't → return `false`.
3. Compare the current node values.
4. Recursively compare:
   - Left subtree
   - Right subtree
5. Return `true` only if:
   - Current values match
   - Left subtrees are identical
   - Right subtrees are identical

---

## ✅ Algorithm

1. Check if both nodes are `NULL`.
2. Check if only one node is `NULL`.
3. Compare current node values.
4. Recursively compare left children.
5. Recursively compare right children.
6. Return the combined result.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every node is visited exactly once.

- **Space Complexity:** `O(h)`
  - Recursive call stack.
  - `h` = height of the tree.
  - Worst case: `O(n)`
  - Balanced tree: `O(log n)`

---

## 🧠 Key Concepts

- Binary Trees
- Recursion
- Depth-First Search (DFS)
- Tree Traversal

---

## 🚀 Example

### Input

```text
p = [1,2,3]
q = [1,2,3]
```

### Output

```text
true
```

---

### Input

```text
p = [1,2]
q = [1,null,2]
```

### Output

```text
false
```

---

## 📖 What I Learned

- How to compare two trees recursively.
- Proper handling of `NULL` nodes.
- Combining recursive results from left and right subtrees.
- A clean DFS approach for tree comparison problems.

---

## 🏷️ Tags

`Binary Tree` `DFS` `Recursion` `Tree Traversal`