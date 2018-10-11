class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2 || k < 1 || t < 0) return false;
        unordered_map<long long, long long> ump;
        for(int i=0; i<nums.size(); i++) {
            long long n = (long long)nums[i] - INT_MIN;
            long long id = n / ((long long)t+1);
            if(ump.find(id) != ump.end() || (ump.find(id-1) != ump.end() && nums[i] - ump[id-1] <= t)
              || (ump.find(id+1) != ump.end() && ump[id+1] - nums[i] <= t)) return true;
            if(ump.size() >= k) ump.erase(((long long)nums[i-k]-INT_MIN) / ((long long)t+1));
            ump[id] = nums[i];
        }
        return false;
    }
};