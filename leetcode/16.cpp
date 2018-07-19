class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() <= 3) {
            int ans = 0;
            for(int i=0; i<nums.size(); i++) ans+= nums[i];
            return ans;
        }
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size()-1;
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0; i<nums.size(); i++){
            s = i+1;
            e = nums.size()-1;
            while(s < e){
                int current = nums[i] + nums[s] + nums[e];
                if(abs(target - current) < abs(target - ans)){
                    ans = current;
                    if(ans == target) return target;
                }
                if(current > target) e--;
                else s++;
            }
        }
        return ans;
    }
};