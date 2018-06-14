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
    vector<int> v;
    void preorder(TreeNode* root){
        if(root == NULL) return;
        v.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        int ret = INT_MAX;
        preorder(root);
        sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++){
            ret = min(ret, v[i]-v[i-1]);
        }
        return ret;
    }
};