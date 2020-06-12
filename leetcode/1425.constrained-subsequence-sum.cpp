/*
 * @lc app=leetcode id=1425 lang=cpp
 *
 * [1425] Constrained Subsequence Sum
 */

// @lc code=start
class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = nums[0];
        deque<pair<int, int>> d;
        d.push_back({0, nums[0]});
        for(int i=1; i<n; i++) {
            if(d.front().first + k < i) d.pop_front();
            nums[i] = max(nums[i], nums[i] + d.front().second);
            while(!d.empty() && nums[i] >= d.back().second) d.pop_back();
            d.push_back({i, nums[i]});
            ans = max(ans, nums[i]);
        }
        return ans;
    }
};
// @lc code=end

