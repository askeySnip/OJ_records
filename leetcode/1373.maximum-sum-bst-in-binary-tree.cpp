/*
 * @lc app=leetcode id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
 public:
  int ans;
  tuple<bool, int, int, int> helper(TreeNode* root) {
    bool l1, r1;
    int l2, l3, l4, r2, r3, r4;
    if (root->left && root->right) {
      tuple<bool, int, int, int> l = helper(root->left);
      tuple<bool, int, int, int> r = helper(root->right);
      tie(l1, l2, l3, l4) = l;
      tie(r1, r2, r3, r4) = r;
      if (l1 && r1 && l4 < root->val && r3 > root->val) {
        int s = l2 + r2 + root->val;
        ans = max(ans, s);
        return {true, s, l3, r4};
      }
      return {false, 0, 0, 0};
    } else if (root->left) {
      tuple<bool, int, int, int> l = helper(root->left);
      tie(l1, l2, l3, l4) = l;
      if (l1 && l4 < root->val) {
        int s = l2 + root->val;
        ans = max(ans, s);
        return {true, s, l3, root->val};
      }
      return {false, 0, 0, 0};
    } else if(root->right) {
      tuple<bool, int, int, int> r = helper(root->right);
      tie(r1, r2, r3, r4) = r;
      if (r1 && r3 > root->val) {
        int s = r2 + root->val;
        ans = max(ans, s);
        return {true, s, root->val, r4};
      }
      return {false, 0, 0, 0};
    }
    ans = max(ans, root->val);
    return {true, root->val, root->val, root->val};
  }
  int maxSumBST(TreeNode* root) {
    ans = 0;
    helper(root);
    return ans;
  }
};
// @lc code=end
