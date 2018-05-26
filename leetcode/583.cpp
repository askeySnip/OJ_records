class Solution {
public:
    int minDistance(string word1, string word2) {
        int dp[520][520];
        int len1 = word1.length(), len2 = word2.length();
        word1 = "0"+word1;
        word2 = "0"+word2;
        for(int i=0; i<=len1; i++){
            for(int j=0; j<=len2; j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    dp[i][j] = (word1[i] == word2[j])? dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return len1+len2-2*dp[len1][len2];
    }
};