class Solution {
public:
    int gn, gk;
    void dfs(int t, vector<vector<int> >& ret, vector<int> v){
        v.push_back(t);
        if(v.size() == gk) {
            ret.push_back(v);
            return;
        }
        for(int i=t+1; i<=gn; i++){
            dfs(i, ret, v);
        }
        v.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > ret;
        vector<int> v;
        gn = n;
        gk = k;
        for(int i=1; i<=n-k+1; i++){
            dfs(i, ret, v);
        }
        return ret;
    }
};