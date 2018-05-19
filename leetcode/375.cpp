class Solution {
public:
    int dp[1000][1000];
    int getMoneyAmount(int n) {
        if(n == 1) return 0;
        if(n == 2) return 1;
        memset(dp, 0, sizeof(dp));
        return helper(1, n);
    }
    int helper(int s, int e){
        if(s >= e) return 0;
        if(s+1 == e) return s;
        if(dp[s][e] != 0) return dp[s][e];
        int ret = 1<<30;
        for(int i=s+1; i<e; i++){
            dp[s][i-1] = helper(s, i-1);
            dp[i+1][e] = helper(i+1, e);
            int t = max(dp[s][i-1], dp[i+1][e]) + i;
            ret = min(ret, t);
        }
        return ret;
    }
};