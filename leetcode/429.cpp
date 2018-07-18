/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void bfs(vector<vector<int> >& ret, vector<vector<Node*> >& t, int& c){
        if(t[c].size() == 0) return;
        vector<int> toadd;
        for(int i=0; i<t[c].size(); i++){
            toadd.push_back(t[c][i]->val);
        }
        ret.push_back(toadd);
        for(int i=0; i<t[c].size(); i++){
            t[1-c].insert(t[1-c].end(), t[c][i]->children.begin(), t[c][i]->children.end());
        }
        t[c].clear();
        c = 1-c;
        bfs(ret, t, c);
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > ret;
        if(root == NULL) return ret;
        vector<vector<Node*> > t;
        t.resize(2);
        t[0].push_back(root);
        int c = 0;
        bfs(ret, t, c);
        return ret;
    }
};