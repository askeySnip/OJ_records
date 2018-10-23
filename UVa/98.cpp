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
private:
    long long last = -(10e15);
    bool preorder(TreeNode* root) {
        if(root == NULL) return true;
        bool f = preorder(root->left);
        if(!f) return false;
        if(root->val <= last) return false;
        last = root->val;
        
        return preorder(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return preorder(root);
    }
};