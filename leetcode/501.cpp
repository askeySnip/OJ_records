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
    vector<int> modes;
    
    vector<int> findMode(TreeNode* r) {
      int mfq/*max freq*/, pre/*previous val*/, cnt/*duplicates count*/;
      getMaxFreq(r, mfq=0, pre, cnt=0); // in-order traversal to get max frequency
      getMode(r, mfq, pre, cnt=0);      // in-order traversal to get all modes
      return modes;
    }
    
    void getMaxFreq(TreeNode* r, int& mfq, int& pre, int& cnt) {
      if (!r) return;
      getMaxFreq(r->left, mfq, pre, cnt);
      getMaxFreq(r->right, mfq=max(mfq,cnt), pre=r->val, ++(cnt*=(r->val==pre)));
    }
    
    void getMode(TreeNode* r, const int mfq, int& pre, int& cnt) {
      if (!r) return;
      getMode(r->left, mfq, pre, cnt);
      if (mfq == ++(cnt*=(r->val==pre))) modes.push_back(r->val);
      getMode(r->right, mfq, pre=r->val, cnt);
    }
};