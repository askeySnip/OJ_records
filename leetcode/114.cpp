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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        if(root->left == NULL){
            flatten(root->right);
        }else{
            if(root->left->left == NULL && root->left->right == NULL) {
                TreeNode* p = root->right;
                root->right = root->left;
                root->left = NULL;
                root->right->right = p;
                flatten(p);
                flatten(root);
            }else if(root->left->left == NULL){
                flatten(root->left->right);
                TreeNode* p = root->right;
                TreeNode* t = root->left;
                while(t->right!=NULL) t=t->right;
                root->right = root->left;
                root->left = NULL;
                t->right = p;
                flatten(p);
            }else{
                flatten(root->left);
                flatten(root);
            }
        }
    }
};