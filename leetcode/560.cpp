class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int c = 0;
        if(nums[0] == k) c++;
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] == k) c++;
            nums[i] += nums[i-1];
            if(nums[i] == k) c++;
        }
        for(int len=2; len<n; len++){
            for(int i=1; i+len<=n; i++){
                if(nums[i+len-1]-nums[i-1] == k) c++;
            }
        }
        return c;
    }
};

// better solution
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map <int, int> map;
        
        int sum = 0;
        
        map[0] = 1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum+=nums[i];
            int find_v = sum - k;
            if (map.find(find_v) != map.end()) {
                ret += map[find_v];
            }
            
            // sum+=nums[i];
            map[sum]++;
        }
        
        return ret;
        
    }
};