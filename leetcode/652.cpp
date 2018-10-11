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
    map<string, int> mp;
    vector<TreeNode*> ret;
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root == NULL) return ret;
        preorder(root);
        return ret;
    }
    string preorder(TreeNode* root) {
        if(root == NULL) return "#";
        string s = to_string(root->val) + "," + preorder(root->left) + "," + preorder(root->right);
        if(mp.find(s) != mp.end() && mp[s] == 1) {ret.push_back(root); mp[s]++;}
        else mp[s]++;
        return s;
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
private:
	using HashMap = unordered_map<string, vector<TreeNode*>>;
	string serialize(TreeNode* root, HashMap& dp) {
		if (!root) return "";
		string soln = "(" + serialize(root->left, dp) + to_string(root->val) + serialize(root->right, dp) + ")";
		dp[soln].push_back(root);
		return soln;
	}
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		/*
		 * utilize hashmap to deduplicate
		 */
		HashMap dp;
		serialize(root, dp);
		vector<TreeNode*> soln;
		for(auto& p : dp) {
			if (p.second.size() > 1) soln.push_back(p.second[0]);
		}
		return soln;
	}
};