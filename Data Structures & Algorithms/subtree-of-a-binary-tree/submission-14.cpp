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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSametree(root, subRoot)) return true;

        return (isSubtree(root->right, subRoot) || 
            isSubtree(root->left, subRoot));
    }
    bool isSametree(TreeNode* t1, TreeNode* t2){
        if (!t1 && !t2) { return true; }
        if (!t1 || !t2) { return false; }
        if (t1->val != t2->val) { return false; }

        return (isSametree(t1->right, t2->right) &&
            isSametree(t1->left, t2->left));
    }
};
