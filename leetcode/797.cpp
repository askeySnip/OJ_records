class Solution {
public:
    vector<vector<int> > ret;
    int n;
    void dfs(vector<vector<int> >& graph, vector<int>& v, int c){
        if(c == n-1) {ret.push_back(v); return;}
        for(int i=0; i<graph[c].size(); i++){
            v.push_back(graph[c][i]);
            dfs(graph, v, graph[c][i]);
            v.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int> v;
        v.push_back(0);
        dfs(graph, v, 0);
        return ret;
    }
};