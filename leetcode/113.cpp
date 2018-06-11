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
    vector<vector<int> > ret;
    void dfs(TreeNode* root, int sum, vector<int>& v){
        if(root->left == NULL && root->right == NULL && sum == root->val){
            v.push_back(sum);
            ret.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        if(root->left != NULL){
            dfs(root->left, sum-root->val, v);
        }
        if(root->right != NULL){
            dfs(root->right, sum-root->val, v);
        }
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return ret;
        vector<int> v;
        dfs(root, sum, v);
        return ret;
    }
};