LeetCode 94 - Binary Tree Inorder Traversal
Problem Statement
Given the root of a binary tree, return the inorder traversal of its nodes' values.
In inorder traversal, we visit the nodes in the following order:
Left → Root → Right
For example:
      1
       \
        2
       /
      3
The inorder traversal is:
[1, 3, 2]
Approach
We can solve this problem using recursion.
For every node:
Traverse its left subtree.
Add the current node's value to the result.
Traverse its right subtree.
This follows the inorder pattern:
Left → Root → Right
A helper function traverse() is used to recursively visit every node.
Algorithm
Create an empty vector res.
Start the recursive traversal from root.
If the current node is nullptr, return.
Recursively traverse the left subtree.
Add the current node's value to res.
Recursively traverse the right subtree.
Return res.
Dry Run
Consider the following tree:
        1
         \
          2
         /
        3
Start at node 1.
Node 1
Traverse left:
nullptr
Add 1:
result = [1]
Traverse right → node 2.
Node 2
Traverse left → node 3.
Node 3
Traverse left:
nullptr
Add 3:
result = [1, 3]
Traverse right:
nullptr
Return to node 2.
Add 2:
result = [1, 3, 2]
Final result:
[1, 3, 2]
C++ Solution
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    void traverse(TreeNode* n, vector<int>& result) {
        if(!n) return;

        traverse(n->left, result);
        result.push_back(n->val);
        traverse(n->right, result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        traverse(root, res);

        return res;
    }
};
Complexity Analysis
Time Complexity
O(n)
Every node in the binary tree is visited exactly once.
Space Complexity
O(h)
The recursive call stack can contain up to h nodes, where h is the height of the tree.
In the worst case, when the tree is completely skewed:
O(n)
Concepts Used
Binary Tree
Tree Traversal
Recursion
Depth First Search (DFS)
Inorder Traversal
LeetCode Details
Property	Details
Problem	94. Binary Tree Inorder Traversal
Difficulty	Easy
Language	C++
Approach	Recursion
Traversal	Left → Root → Right
Time Complexity	O(n)
Space Complexity	O(h)