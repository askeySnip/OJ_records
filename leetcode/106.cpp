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
    TreeNode* helper(vector<int>& inorder, int si, int ei, vector<int>& postorder, int sp, int ep){
        if(si == ei){
            TreeNode* ret = new TreeNode(inorder[si]);
            return ret;
        }
        if(si > ei) return NULL;
        int rootval = postorder[ep--];
        TreeNode* root = new TreeNode(rootval);
        for(int i=si; i<=ei; i++){
            if(inorder[i] == rootval){
                root->left = helper(inorder, si, i-1, postorder, sp, sp+i-1-si);
                root->right = helper(inorder, i+1, ei, postorder, sp+i-si, ep);
                break;
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0) return NULL;
        return helper(inorder, 0, postorder.size()-1, postorder, 0, postorder.size()-1);
    }
};