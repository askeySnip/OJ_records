class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] <= nums.back()) return nums[0];
        int l=0, h=nums.size()-1, mid;
        while(l < h) {
            mid = (l+h)/2;
            if(nums[mid] > nums[h]) {
                l = mid+1;
            }else {
                h = mid;
            }
        }
        return nums[l];
    }
};



class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        
        int start = 0;
        int end = size - 1;
        int mid = (start + end) / 2;
        
        while (end - mid > 0) {
            if (nums[mid] < nums[end])
                end = mid;
            else
                start = mid + 1;
            mid = (start + end) / 2;
        }
        
        return nums[mid];
    }
};