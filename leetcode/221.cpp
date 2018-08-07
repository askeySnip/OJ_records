class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0) return 0;
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int> > dp(r, vector<int>(c));
        int ans = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                dp[i][j] = matrix[i][j]-'0';
                if(dp[i][j]) ans = 1;
            }
        }
        for(int i=1; i<r; i++) {
            for(int j=1; j<c; j++) {
                if(dp[i][j] == 0) continue;
                if(dp[i-1][j] && dp[i][j-1] && dp[i-1][j-1]) {
                    dp[i][j] = max(dp[i][j], min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]))+1);
                    ans = max(dp[i][j], ans);
                }
            }
        }
        return ans*ans;
    }
};