class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size()-1;
        while(1) {
            int p = partation(nums, l, r);
            // // cout << "!" << p << endl;
            if(p == k-1) {
                return nums[p];
            }else if(p < k - 1) {
                l = p + 1;
            }else {
                r = p - 1;
            }
        }
    }
    
    int partation(vector<int>& nums, int& ll, int& rr) {
        int privot = nums[ll], l = ll + 1, r = rr;
        while(l <= r) {
            if(nums[l] < privot && nums[r] > privot) swap(nums[l++], nums[r--]);
            if(nums[l] >= privot) l++;
            if(nums[r] <= privot) r--;
            // cout << l << r << endl;
        }
        swap(nums[ll], nums[r]);
        return r;
    }
};