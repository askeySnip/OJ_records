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
    void preorder(TreeNode* root, int& ans, bool l){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL && l) ans+=root->val;
        else{
            if(root->left){
                preorder(root->left, ans, true);
            }
            if(root->right){
                preorder(root->right, ans, false);
            }
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return 0;
        preorder(root->left, ans, true);
        preorder(root->right, ans, false);
        return ans;
    }
};



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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        stack<TreeNode*> tree;
        while (root || !tree.empty()) {
            if (root) {
                tree.push(root);
                root = root->left;
            }
            else {
                TreeNode* node = tree.top();
                if (node->left != NULL && !node->left->left && !node->left->right) sum += node->left->val;
                root = node->right;
                tree.pop();
            }
        }
        return sum;
    }
};