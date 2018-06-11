class Solution {
public:
    int ans = 0;
    int gn;
    vector<int> row, rl, ll;
    void dfs(int d){
        if(d == gn) {
            ans++;
            return;
        }
        d++;
        for(int i=1; i<=gn; i++){
            if(row[i] || rl[d+i] || ll[d-i+gn]) continue;
            row[i] = 1;
            rl[d+i] = 1;
            ll[d-i+gn] = 1;
            dfs(d);
            row[i] = 0;
            rl[d+i] = 0;
            ll[d-i+gn] = 0;
        }
    }
    int totalNQueens(int n) {
        gn = n;
        row.assign(n*2+2, 0);
        rl.assign(n*2+2, 0);
        ll.assign(n*2+2, 0);
        for(int i=1; i<=n; i++){
            row[i] = 1;
            rl[1+i] = 1;
            ll[1-i+n] = 1;
            dfs(1);
            row[i] = 0;
            rl[1+i] = 0;
            ll[1-i+n] = 0;
        }
        return ans;
    }
};