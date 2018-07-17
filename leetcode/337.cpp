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
    int helper(TreeNode* root, bool choose){
        if(choose){
            // return rob(root->left->left) + rob(root->left->right) + rob(root->right->left) + rob(root->right->right);
            int ret = 0;
            if(root->left != NULL)
                ret += rob(root->left->left) + rob(root->left->right);
            if(root->right != NULL)
                ret += rob(root->right->left) + rob(root->right->right);
            return ret;
        }else{
            return rob(root->left) + rob(root->right);
        }
    }
    int rob(TreeNode* root) {
        if(root == NULL) return 0;
        return max(helper(root, true)+root->val, helper(root, false));
    }
};





// a better solvstion


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
    int rob(TreeNode* root) {
        if(!root){
            return 0;
        }   
        int no_take = 0;
        int with = take_this_group(root, no_take);
        return max(with,no_take);
    }
    
    int take_this_group(TreeNode* root, int& no_take){
        
        //The idea is to find group with root, find group w/o,
        //and the return maximum on them. 
        if(!root){
            no_take =0;
            return 0;
        }
        
        if(!root->left && !root->right){
            no_take =0;
            return root->val;    
        }
        
        int no_take_left =0, no_take_right =0; 
        
        int left_val = take_this_group(root->left, no_take_left);
        int right_val = take_this_group(root->right, no_take_right);
        
        no_take = max(left_val, no_take_left) + max(right_val, no_take_right);
        return no_take_left + no_take_right + root->val;
    }
    
    
    
};