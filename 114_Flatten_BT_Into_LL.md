# 114. Flatten Binary Tree to Linked List

## 📝 Problem Statement

Given the root of a binary tree, flatten the tree into a linked list **in-place**.

The linked list should:

- Use the same `TreeNode` structure.
- Have each node's `right` pointer point to the next node.
- Have every `left` pointer set to `NULL`.
- Follow the **Preorder Traversal** sequence (Root → Left → Right).

**LeetCode Link:** https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

---

## 💡 Approach

This solution uses **Reverse Preorder Traversal**:

**Traversal Order:**
```
Right → Left → Root
```

A pointer `prev` keeps track of the previously processed node.

For every node:

1. Flatten the right subtree.
2. Flatten the left subtree.
3. Point the current node's `right` to `prev`.
4. Set its `left` to `NULL`.
5. Update `prev` to the current node.

Since nodes are processed in reverse preorder, rebuilding the links naturally creates the required preorder linked list.

---

## 🚀 Algorithm

1. If the current node is `NULL`, return.
2. Recursively flatten the right subtree.
3. Recursively flatten the left subtree.
4. Set:
   - `root->right = prev`
   - `root->left = NULL`
5. Update `prev = root`.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    TreeNode* prev = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;

        prev = root;
    }
};
```

---

## 🌳 Example

### Input

```text
        1
      /   \
     2     5
    / \     \
   3   4     6
```

### Flattened Tree

```text
1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
```

### Output

```text
[1,null,2,null,3,null,4,null,5,null,6]
```

---

## 🔍 Dry Run

### Initial `prev = NULL`

Process order:

```
6 → 5 → 4 → 3 → 2 → 1
```

Updates:

```
6 → NULL
5 → 6
4 → 5
3 → 4
2 → 3
1 → 2
```

Final linked list:

```
1 → 2 → 3 → 4 → 5 → 6
```

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every node is visited exactly once.

- **Space Complexity:** `O(h)`
  - Recursive call stack.
  - Worst case: `O(n)` (skewed tree).
  - Best/Average case: `O(log n)` (balanced tree).

---

## 🔑 Key Insight

Instead of flattening in preorder directly, process the tree in **reverse preorder (Right → Left → Root)**.

Keeping a global `prev` pointer allows every node to connect directly to the next node in preorder without requiring any additional data structures.

---

### 🏷️ Tags

`Tree` `Depth-First Search` `Binary Tree` `Recursion`