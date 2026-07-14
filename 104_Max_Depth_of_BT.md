# 104. Maximum Depth of Binary Tree

> **Difficulty:** Easy  
> **Language:** C++  
> **Runtime:** 0 ms *(Beats 100%)*

## 📝 Problem Statement

Given the `root` of a binary tree, return its **maximum depth**.

The maximum depth is the **number of nodes** along the longest path from the root node to the farthest leaf node.

---

## 💡 Approach

This problem is naturally solved using **Depth-First Search (DFS)** with recursion.

For every node:

- Recursively find the maximum depth of the left subtree.
- Recursively find the maximum depth of the right subtree.
- The current node's depth is:

```text
1 + max(leftDepth, rightDepth)
```

The recursion continues until a `NULL` node is reached.

---

## 🔄 Algorithm

1. If the current node is `NULL`, return `0`.
2. Recursively compute the depth of the left subtree.
3. Recursively compute the depth of the right subtree.
4. Return:

```text
max(leftDepth, rightDepth) + 1
```

---

## ✅ Code

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return max(left, right) + 1;
    }
};
```

---

## 📊 Example

### Input

```text
root = [3,9,20,null,null,15,7]
```

### Tree

```text
        3
       / \
      9  20
         / \
        15  7
```

### Execution

```text
Depth(9)  = 1
Depth(15) = 1
Depth(7)  = 1

Depth(20) = max(1,1) + 1 = 2

Depth(3) = max(1,2) + 1 = 3
```

### Output

```text
3
```

---

## ⏱ Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(h)`

Where:

- `n` = number of nodes
- `h` = height of the tree (recursive call stack)

Worst case:

```text
O(n)
```

Balanced tree:

```text
O(log n)
```

---

## 🧠 Key Insight

The depth of any node depends only on the deeper of its two subtrees.

By recursively computing the depth of the left and right children and taking their maximum, we can determine the tree's maximum depth efficiently with a single traversal.

---

⭐ If you found this solution helpful, consider giving the repository a star!