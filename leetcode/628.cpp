class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int t = max(nums[0]*nums[1], nums[n-2] * nums[n-3]);
        return t * nums[n-1];
    }
};