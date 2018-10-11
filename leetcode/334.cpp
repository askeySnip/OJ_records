class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        if(nums.size() < 3) return false;
        vector<int> a;
        for(int i=0; i<nums.size(); i++) {
            if(a.size() == 0) a.push_back(nums[i]);
            else{
                int j=0;
                for(; j<a.size(); j++) {
                    if(a[j] < nums[i]) continue;
                    else {
                        a[j] = nums[i];
                        break;
                    }
                }
                if(j == a.size()) a.push_back(nums[i]);
                if(a.size() >= 3) return true;
            }
        }
        return false;
    }
};