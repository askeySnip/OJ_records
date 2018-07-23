class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int last = nums[0];
        int ans = 1, t = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i] > last) t++;
            else {
                ans = max(t, ans);
                t = 1;
            }
            last = nums[i];
        }
        ans = max(t, ans);
        return ans;
    }
};