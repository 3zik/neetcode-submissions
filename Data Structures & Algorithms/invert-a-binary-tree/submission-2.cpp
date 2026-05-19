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
public:
    TreeNode* invertTree(TreeNode* root) {
        return dfs(root);
    }
    TreeNode* dfs(TreeNode* root){
        // simply swapping two children of binary tree
        if (!root) return nullptr;

        TreeNode* left = dfs(root->right);
        TreeNode* right = dfs(root->left);

        root->left = left; 
        root->right = right;

        return root;
    }
};
