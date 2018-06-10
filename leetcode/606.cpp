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
    string tree2str(TreeNode* t) {
        string ret;
        if(t==NULL) return ret;
        ret += to_string(t->val);
        string l = tree2str(t->left);
        string r = tree2str(t->right);
        if(r!=""){
            ret += "(" + l + ")(" + r + ")";
        }else{
            if(l != ""){
                ret += "(" + l + ")";
            }
        }
        // cout << t->val << " " << ret << endl;
        return ret;
    }
};