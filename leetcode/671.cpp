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
    int findSecondMinimumValue(TreeNode* root) {
         v.push_back(root->val);
        helper(root, root->val);
        sort(v.begin(), v.end());
        if(v.size() == 1) return -1;
        else return v[1];
    }
    void helper(TreeNode* root, int value){
        if(root->right==NULL) return;
        int t = value;
        if(root->right->val == t) {
            helper(root->left, value);
            helper(root->right, value);
        }else{
            v.push_back(root->right->val);
        }
        if(root->left->val == t) {
            helper(root->left, value);
            helper(root->right, value);
        }else{
            v.push_back(root->left->val);
        }
        
    }
};