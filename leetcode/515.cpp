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
    void dfs(TreeNode* root, vector<int>& ret, int d){
        if(root == NULL) return;
        if(ret.size() < d) ret.push_back(root->val);
        else{
            ret[d-1] = max(ret[d-1], root->val);
        }
        dfs(root->left, ret, d+1);
        dfs(root->right, ret, d+1);
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        dfs(root, ret, 1);
        return ret;
    }
};