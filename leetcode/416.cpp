class Solution {
public:
    bool dfs(vector<int>& nums, int i, int target){
        if(target == 0) return true;
        else if(target < 0) return false;
        else if(i < 0) return false;
        int k = i-1;
        while(k >= 0 && nums[k-1] == nums[k]){
            k--;
        }
        return dfs(nums, i-1, target-nums[i]) || dfs(nums, k, target);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return false;
        int s = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++) s+=nums[i];
        if(s%2) return false;
        s /= 2;
        return dfs(nums, n-1, s);
    }
};