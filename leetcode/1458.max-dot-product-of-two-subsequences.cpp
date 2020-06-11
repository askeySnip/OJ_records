/*
 * @lc app=leetcode id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

// @lc code=start
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int ans = -0x3f3f3f3f;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                ans =  max(ans, nums1[i] * nums2[j]);
            }
        }
        if(ans <= 0) return ans;
        vector<int> f(m+1, 0);
        for(int i=0; i<n; i++) {
            for(int j=m-1; j>=0; j--) {
                f[j+1] = max(f[j+1], f[j] + nums1[i] * nums2[j]);
            }
            for(int j=0; j<m; j++) {
                f[j+1] = max(f[j], f[j+1]);
            }
        }
        return *max_element(f.begin(), f.end());
        
    }
};
// @lc code=end

