/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool flag;
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        flag = true;
        int l = depth(root->left), r = depth(root->right);
        if(abs(l-r) > 1) flag = false;
        return flag;
    }
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        if(!flag) return 0;
        int l = depth(root->left), r = depth(root->right);
        if(abs(l-r) > 1) flag = false;
        return max(l, r) + 1;
    }
};