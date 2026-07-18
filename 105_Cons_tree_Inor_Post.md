# 105. Construct Binary Tree from Preorder and Inorder Traversal

> **Difficulty:** Medium  
> **Language:** C++  
> **Runtime:** 0 ms *(Beats 100%)*

## 📝 Problem Statement

Given two integer arrays:

- `preorder` → Preorder traversal of a binary tree.
- `inorder` → Inorder traversal of the same binary tree.

Construct and return the original binary tree.

It is guaranteed that:

- Every value is unique.
- Both traversals represent the same valid binary tree.

---

## 💡 Approach

The solution uses **Recursion + Hash Map**.

### Key Observations

- In **Preorder Traversal**, the **first element is always the root**.
- In **Inorder Traversal**:
  - Elements left of the root belong to the left subtree.
  - Elements right of the root belong to the right subtree.

To avoid searching for the root every time, store each value's index in the inorder array using a **Hash Map (`unordered_map`)**.

---

## 🔄 Algorithm

1. Store every value and its index from the inorder array in a hash map.
2. Maintain an index pointing to the current root in the preorder array.
3. Create the root node using the current preorder value.
4. Find its position in the inorder array.
5. Recursively build:
   - Left subtree
   - Right subtree
6. Return the constructed tree.

---

## ✅ Code

```cpp
class Solution {
    unordered_map<int, int> inorderIndex;
    int preorderIndex = 0;

    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right)
            return nullptr;

        int rootValue = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(rootValue);

        int index = inorderIndex[rootValue];

        root->left = build(preorder, left, index - 1);
        root->right = build(preorder, index + 1, right);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        for (int i = 0; i < inorder.size(); i++)
            inorderIndex[inorder[i]] = i;

        return build(preorder, 0, inorder.size() - 1);
    }
};
```

---

## 📊 Example

### Input

```text
preorder = [3,9,20,15,7]

inorder = [9,3,15,20,7]
```

### Construction

```text
Preorder

3 → Root

Inorder

9 | 3 | 15 20 7
    ↑

Left Subtree:
9

Right Subtree:
20
├──15
└──7
```

### Final Tree

```text
        3
       / \
      9   20
         /  \
        15   7
```

### Output

```text
[3,9,20,null,null,15,7]
```

---

## ⏱ Complexity Analysis

### Time Complexity

- Building Hash Map → **O(n)**
- Visiting each node once → **O(n)**

**Overall:**

```text
O(n)
```

### Space Complexity

- Hash Map → **O(n)**
- Recursive stack → **O(h)**

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

The preorder traversal always tells us **which node to create next**, while the inorder traversal tells us **where to split the tree into left and right subtrees**.

Using a hash map to instantly locate each root in the inorder array avoids repeated searches, reducing the overall complexity from **O(n²)** to **O(n)**.

---

⭐ If you found this solution helpful, consider giving the repository a star!83_