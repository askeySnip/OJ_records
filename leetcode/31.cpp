class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
        if (k < 0) {
            reverse(nums, 0, n - 1);
        } else {
            for (l = n - 1; l >= 0; l--) {
                if (nums[k] < nums[l]) {
                    break;
                }
            }
            swap(nums, k, l);
            reverse(nums, k + 1, n - 1);
        }
    }
    
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
    }
    
    void reverse(vector<int>& nums, int l, int r) {
        while (l < r) {
            swap(nums, l++, r--);
        }
    }
    
};