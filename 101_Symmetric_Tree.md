# 101. Symmetric Tree

## 📝 Problem Statement

Given the root of a binary tree, determine whether it is a mirror of itself (i.e., symmetric around its center).

A tree is symmetric if the left subtree is a mirror reflection of the right subtree.

**LeetCode Link:** https://leetcode.com/problems/symmetric-tree/

---

## 💡 Approach

Use **recursive DFS** to compare the left and right subtrees.

For two trees to be mirrors:

- Both nodes must be `NULL`, or
- Both nodes must exist and have the same value.
- The **left child** of the first tree must match the **right child** of the second tree.
- The **right child** of the first tree must match the **left child** of the second tree.

If all these conditions hold recursively, the tree is symmetric.

---

## 🚀 Algorithm

1. Create a helper function `check(leftTree, rightTree)`.
2. If both nodes are `NULL`, return `true`.
3. If one node is `NULL` and the other isn't, return `false`.
4. If their values differ, return `false`.
5. Recursively compare:
   - `leftTree->left` with `rightTree->right`
   - `leftTree->right` with `rightTree->left`
6. Return the logical AND of both recursive calls.

---

## ✅ C++ Solution

```cpp
class Solution {
public:
    bool check(TreeNode* LTree, TreeNode* RTree) {
        if (LTree == NULL && RTree == NULL)
            return true;

        if (LTree == NULL || RTree == NULL)
            return false;

        if (LTree->val != RTree->val)
            return false;

        return check(LTree->left, RTree->right) &&
               check(LTree->right, RTree->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};