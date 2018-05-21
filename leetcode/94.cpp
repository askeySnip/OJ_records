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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorder(root, ret);
        return ret;
    }
    void inorder(TreeNode* root, vector<int>& ret){
        if(root == NULL) return;
        inorder(root->left, ret);
        ret.push_back(root->val);
        inorder(root->right, ret);
    }
};