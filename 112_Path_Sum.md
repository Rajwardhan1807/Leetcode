# 112. Path Sum

## 📝 Problem Statement

Given the root of a binary tree and an integer `targetSum`, determine if the tree has a **root-to-leaf** path such that the sum of all node values along the path equals `targetSum`.

A **leaf** is a node with no left or right child.

**LeetCode Link:** https://leetcode.com/problems/path-sum/

---

## 💡 Approach

Use **Depth-First Search (DFS)** recursively.

At each node:

- Subtract the current node's value from `targetSum`.
- Continue searching in the left and right subtrees.
- When a leaf node is reached, check whether its value equals the remaining target.

If either subtree contains a valid path, return `true`.

---

## 🚀 Algorithm

1. If the tree is empty, return `false`.
2. If the current node is a leaf:
   - Return `true` if `root->val == targetSum`.
3. Recursively search:
   - Left subtree with `targetSum - root->val`
   - Right subtree with `targetSum - root->val`
4. Return `true` if either recursive call returns `true`.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL)
            return root->val == targetSum;

        bool left = hasPathSum(root->left, targetSum - root->val);
        bool right = hasPathSum(root->right, targetSum - root->val);

        return left || right;
    }
};
```

---

## 🌳 Example

### Input

```text
           5
         /   \
        4     8
       /     / \
     11    13   4
    /  \          \
   7    2          1

Target Sum = 22
```

### Valid Path

```text
5 → 4 → 11 → 2
```

```
5 + 4 + 11 + 2 = 22
```

### Output

```text
true
```

---

## 🔍 Dry Run

```
Target = 22

Node 5
Remaining = 17

    Node 4
    Remaining = 13

        Node 11
        Remaining = 2

            Node 7
            Remaining = -5 ❌

            Node 2
            Remaining = 0 ✅
```

A valid root-to-leaf path is found, so return `true`.

---

## ⏱️ Complexity Analysis

- **Time Complexity:** `O(n)`
  - Every node is visited once.

- **Space Complexity:** `O(h)`
  - Recursive call stack.
  - Worst case: `O(n)` for a skewed tree.
  - Balanced tree: `O(log n)`.

---

## 🔑 Key Insight

Instead of keeping a running sum, keep reducing the target as you move down the tree.

When you reach a leaf, if the remaining target equals the leaf's value, you've found a valid path.

---

## 🏷️ Tags

`Tree` `Depth-First Search` `Binary Tree` `Recursion`