/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* vector2BST(vector<int>& v, int s, int e){
        if(s == e){
            TreeNode* t = new TreeNode(v[s]);
            return t;
        }
        if(s > e) return NULL;
        int mid = (s+e)/2;
        TreeNode* t = new TreeNode(v[mid]);
        t->left = vector2BST(v, s, mid-1);
        t->right = vector2BST(v, mid+1, e);
        return t;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head != NULL) {v.push_back(head->val); head = head->next;}
        // for(int i=0; i<v.size(); i++) cout << v[i] << " ";
        return vector2BST(v, 0, v.size()-1);
    }
};