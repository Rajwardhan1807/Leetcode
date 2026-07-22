/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool check(TreeNode * LTree, TreeNode * RTree){
        if(LTree == NULL && RTree == NULL){
            return true;
        }
        if(LTree == NULL || RTree == NULL) return false;

        if(LTree->val != RTree->val) return false;

        return check(LTree->left,RTree->right) && check(LTree->right,RTree->left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        bool ans = check(root->left,root->right);

        return ans;
    }
};