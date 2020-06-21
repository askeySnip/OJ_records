/*
 * @lc app=leetcode id=1377 lang=cpp
 *
 * [1377] Frog Position After T Seconds
 */

// @lc code=start
class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        if(target == 1) {
            if(n == 1) return 1;
            else return 0;
        }
        vector<int> e[110];
        for(auto& a : edges) {
            e[a[0]].push_back(a[1]);
            e[a[1]].push_back(a[0]);
        }
        queue<int> q;
        q.push(1);
        double p[110]{};
        p[1] = 1.0;
        int cur = 0;
        for(int i=0; i<t; i++) {
            int sz = q.size();
            for(int j=0; j<sz; j++) {
                int u = q.front(); q.pop();
                if(u == target) {
                    if(e[u].size() <= 1) return p[u];
                    else return 0;
                } else {
                    int cnt = 0;
                    for(auto v : e[u]) {
                        if(p[v]) continue;
                        cnt++;
                        q.push(v);
                    }
                    for(auto v : e[u]) {
                        p[v] = p[u] / cnt;
                    }
                }
            }
        }
        return p[target];
    }
};
// @lc code=end

