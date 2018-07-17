class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i:nums){
            int p = lower_bound(dp.begin(), dp.end(), i) - dp.begin();
            if(p == dp.size()) dp.push_back(i);
            else dp[p] = i;
        }
        return dp.size();
    }
};