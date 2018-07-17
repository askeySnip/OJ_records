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
    void pre_order(TreeNode* root, vector<int>& v, int& k){
        if(v.size() == k) return;
        if(root == NULL) return;
        pre_order(root->left, v, k);
        v.push_back(root->val);
        pre_order(root->right, v, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        pre_order(root, v, k);
        return v[k-1];
    }
};