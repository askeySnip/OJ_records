/*
 * @lc app=leetcode id=1434 lang=cpp
 *
 * [1434] Number of Ways to Wear Different Hats to Each Other
 */

// @lc code=start
class Solution {
public:
    int numberWays(vector<vector<int>>& hats) {
        vector<vector<int>> person(40);
        int n = hats.size(), mod = 1e9+7;

        for(int i=0; i<n; i++) {
            for(auto h : hats[i]) {
                person[h-1].push_back(i);
            }
        }
        vector<int> mask(1<<n);
        mask[0] = 1;
        for(int i=0; i<40; i++) {
            for(int j=(1<<n)-1; j>=0; j--) {
                for(auto p : person[i]) {
                    if(j & (1 << p)) continue;
                    mask[j | (1 << p)] += mask[j];
                    mask[j | (1 << p)] %= mod;
                }
            }
        }
        return mask[(1<<n)-1];
    }
};
// @lc code=end

