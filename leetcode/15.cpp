class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        if(nums.size() < 3) return ret;
        map<int, int> mp;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            mp[-nums[i]] = i;
        }
        
        for(int i=0; i<nums.size(); i = mp[-nums[i]]+1) {
            for(int j=i+1; j<nums.size(); j = mp[-nums[j]]+1) {
                // if(j == i) continue;
                if(mp.find(nums[i]+nums[j]) != mp.end()) {
                    if(mp[nums[i]+nums[j]] > j) {
                        vector<int> v(3);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = -v[0]-v[1];
                        ret.push_back(v);
                    }
                }
            }
        }
        return ret;
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                helper(nums, nums[i], i + 1, nums.size() - 1, ans);
            }
        }
        return ans;
    }
    void helper(vector<int> & nums, int val, int i, int j, vector<vector<int>> & ans) {
        while(i < j) {
            int num = nums[i] + nums[j];
            if (num == -val) {
                ans.push_back({val, nums[i], nums[j]});
                j--;
                while(i < j && nums[j] == nums[j + 1]) j--;
            } else if (num > -val) {
                j--;
            } else {
                i++;
            }
        }
    }
};