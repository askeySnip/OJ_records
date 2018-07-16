class Solution {
public:
    void dfs(vector<vector<int> >& graph, vector<int>& m, bool& ans, int p){
        for(int i=0; i<graph[p].size(); i++){
            if(m[graph[p][i]] == 0){
                m[graph[p][i]] = 3 - m[p];
                dfs(graph, m, ans, graph[p][i]);
            }else if(m[graph[p][i]] != 3 - m[p]){
                ans = false;
                return;
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> m(n, 0);
        bool ans = true;
        for(int i=0; i<n; i++){
            if(m[i] == 0) {
                m[i] = 1;
                dfs(graph, m, ans, i);
            }
            if(!ans) break;
        }
        return ans;
    }
};