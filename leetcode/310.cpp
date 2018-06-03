class Solution {
public:
    vector<vector<int> > g;
    vector<int> vist;
    int mh, gn;
    int dfs(int s, int d){
        if(d > mh) return gn;
        vist[s] = 1;
        int mm = d;
        for(int i=0; i<g[s].size(); i++){
            if(!vist[g[s][i]]){
                int t = dfs(g[s][i], d+1);
                if(t == gn) return gn;
                mm = max(t, mm);
            }
                
        }
        return mm;
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> ans;
        int ne = edges.size();
        g.resize(n);
        vist.assign(n, 0);
        mh = n;
        gn = n;
        for(int i=0; i<ne; i++){
            int a = edges[i].first, b = edges[i].second;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for(int i=0; i<n; i++){
            vist.assign(n, 0);
            int t = dfs(i, 1);
            // cout << i << " " << t << endl;
            if(mh > t){
                mh = t;
                ans.clear();
                ans.push_back(i);
            }else if(mh == t){
                ans.push_back(i);
            }
        }
        return ans;
    }
};