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
    void inorder(TreeNode* root, int sum, vector<int>& v, int& ans){
        if(root == NULL) return;
        for(int i=0; i<v.size(); i++){
            v[i] += root->val;
        }
        v.push_back(root->val);
        for(int i=0; i<v.size(); i++){
            if(v[i] == sum) ans++;
        }
        inorder(root->left, sum, v, ans);
        inorder(root->right, sum, v, ans);
        v.pop_back();
        for(int i=0; i<v.size(); i++){
            v[i] -= root->val;
        }
    }
    int pathSum(TreeNode* root, int sum) {
        vector<int> v;
        int ans = 0;
        inorder(root, sum, v, ans);
        return ans;
    }
};