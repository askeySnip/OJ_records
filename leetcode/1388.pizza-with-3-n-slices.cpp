/*
 * @lc app=leetcode id=1388 lang=cpp
 *
 * [1388] Pizza With 3n Slices
 */

// @lc code=start
class Solution {
public:

    int helper(const vector<int>& slices) {
        int n = slices.size();
        int choose = (n + 1) / 3;
        vector<vector<int>> f(n+1, vector<int>(choose + 1));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=choose; j++) {
                f[i][j] = max(f[i-1][j], (i-2 > 0 ? f[i-2][j-1] : 0) + slices[i-1]);
            }
        }
        return f[n][choose];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> A(slices.begin()+1, slices.end());
        vector<int> B(slices.begin(), slices.end()-1);
        return max(helper(A), helper(B));
    }
};
// @lc code=end

