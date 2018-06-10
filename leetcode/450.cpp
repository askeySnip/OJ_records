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
    int get(TreeNode* root){
        TreeNode* p = root->right;
        while(p->left != NULL) p = p->left;
        int t = p->val;
        if(root->right->left == NULL) root->right = root->right->right;
        else if(p->right != NULL){
            TreeNode* p1 = root->right;
            while(p1->left->left != NULL) p1 = p1->left;
            p1->left = p->right;
        }else{
            TreeNode* p1 = root->right;
            while(p1->left->left != NULL) p1 = p1->left;
            p1->left = NULL;
        }
        delete p;
        return t;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val == key){
            if(root->left != NULL && root->right != NULL){
                root->val = get(root);
                return root;
            }else if(root->left != NULL){
                delete root;
                return root->left;
            }else if(root->right != NULL){
                delete root;
                return root->right;
            }else{
                delete root;
                return NULL;
            }
        }else if(root->val > key) {root->left = deleteNode(root->left, key); return root;}
        else { root->right = deleteNode(root->right, key); return root;}
    }
};