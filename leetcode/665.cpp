class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] >= nums[i-1]) continue;
            int t = nums[i-1];
            nums[i-1] = nums[i];
            if(is_sorted(nums.begin(), nums.end())) return true;
            nums[i-1] = t;
            nums[i] = t;
            return is_sorted(nums.begin(), nums.end());
        }
        return true;
    }
};