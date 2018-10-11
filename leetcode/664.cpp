class Solution {
public:
    int strangePrinter(string s) {
        int len = s.length();
        if(len == 0) return 0;
        int dp[103][103];
        for(int i=0; i<len; i++) dp[i][i] = 1;
        
        for(int i=1; i<len; i++) {
            for(int j=0; j+i<len; j++) {
                dp[j][j+i] = i+1;
                for(int k=j+1; k<=j+i; k++) {
                    int t = dp[j][k-1] + dp[k][j+i];
                    if(s[k-1] == s[j+i]) t--;
                    dp[j][j+i] = min(dp[j][j+i], t);
                }
            }
        }
        return dp[0][len-1];
    }
    
};

class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                dp[i][j] = (i == j) ? 1 : (1 + dp[i + 1][j]);
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i]) dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
        return (n == 0) ? 0 : dp[0][n - 1];
    }
};