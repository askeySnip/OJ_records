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
    int getMinimumDifference(TreeNode* root) {
        int ans = 1e9, last = -1e9;
        inorder(root, ans, last);
        return ans;
    }
    void inorder(TreeNode* root, int& ans, int& last) {
        if(root == NULL) return;
        inorder(root->left, ans, last);
        ans = min(abs(root->val - last), ans);
        last = root->val;
        inorder(root->right, ans, last);
    }
};