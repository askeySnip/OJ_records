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
    TreeNode* t1;
    TreeNode* t2;
    
    int last = INT_MIN;
    vector<TreeNode*> pipv;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        
        if(pipv.size() < 2) pipv.push_back(root);
        else {
            if(t1 == NULL && pipv[1]->val > root->val) t1 = pipv[1];
            if(pipv[1]->val < pipv[0]->val) t2 = pipv[1];
            pipv[0] = pipv[1];
            pipv[1] = root;
        }
        dfs(root->right);
        
    }
    void recoverTree(TreeNode* root) {
        TreeNode* f = new TreeNode(last);
        pipv.push_back(f);
        t1 = NULL;
        t2 = NULL;
        dfs(root);
        if(pipv[1]->val < pipv[0]->val) t2 = pipv[1];
        // cout << t1->val << " "<< t2->val << " " << lastn->val << endl;
        int t = t1->val;
        t1->val = t2->val;
        t2->val = t;
    }
};