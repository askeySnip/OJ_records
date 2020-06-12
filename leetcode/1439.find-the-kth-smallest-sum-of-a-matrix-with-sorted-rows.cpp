/*
 * @lc app=leetcode id=1439 lang=cpp
 *
 * [1439] Find the Kth Smallest Sum of a Matrix With Sorted Rows
 */

// @lc code=start
class Solution {
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& mat, int k) {
        m = mat.size(), n = mat[0].size();
        int l = m, r = 5000*m, ans = -1;
        while(l <= r) {
            int mid = (l + r) / 2;
            int cnt = dfs(mat,  mid, 0, 0, k);
            if (cnt >= k) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
    int dfs(vector<vector<int>>& mat, int target, int r, int s, int k) {
        if(s > target) return 0;
        if(r == m) return 1;
        int ans = 0;
        for (int c = 0; c < n; ++c) {
          int cnt = dfs(mat, target, r + 1, s + mat[r][c], k - ans);
          if (cnt == 0) break;
          ans += cnt;
          if (ans > k) break;  // prune when count > k
        }
        return ans;
    }
};
// @lc code=end

