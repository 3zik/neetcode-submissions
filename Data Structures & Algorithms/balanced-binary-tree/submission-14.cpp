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
    bool isBalanced(TreeNode* root) {
        return (dfs(root)[0] == 1);
    }

    std::vector<int> dfs(TreeNode* root){
        // height of subtrees must differ in height by no more than 1
        // recursively, we also want to check that the subtrees below are balanced
        if (!root) return {1, 0}; // {isBalanced(), height}

        std::vector<int> l = dfs(root->left);
        std::vector<int> r = dfs(root->right);

        int height = 1 + max(l[1], r[1]);

        bool isBalanced = (abs(l[1] - r[1]) <= 1) &&
            (l[0] == 1) && (r[0] == 1);

        return {isBalanced ? 1 : 0, height};
    }
};
