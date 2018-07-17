class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) return -1;
        if(target == nums[0]) return 0;
        else if(target > nums[0]){
            int l = 1, h = nums.size(), mid;
            while(l < h){
                mid = (l+h)/2;
                if(nums[mid] == target) return mid;
                if(nums[mid]>target || nums[mid] < nums[0]) h = mid;
                else l = mid + 1;
            }
            if(l < nums.size() && nums[l] == target) return l;
            else return -1;
        }else{
            int l = 1, h = nums.size(), mid;
            while(l < h){
                mid = (l+h)/2;
                if(nums[mid] == target) return mid;
                if(nums[mid] > nums[0] || nums[mid] < target) l = mid+1;
                else h = mid;
            }
            if(l < nums.size() && nums[l] == target) return l;
            else return -1;
        }
    }
};