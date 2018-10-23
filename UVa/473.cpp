class Solution {
private:
    bool dfs(vector<int>& nums, vector<int>& sums, int index, int target) {
        if(index == nums.size()) {
            for(int i=0; i<4; i++) if(sums[i] != target) return false;
            return true;
        }
        for(int i=0; i<4; i++) {
            if(sums[i] + nums[index] > target) continue;
            sums[i] += nums[index];
            bool f = dfs(nums, sums, index+1, target);
            sums[i] -= nums[index];
            if(f) return true;
        }
        return false;
    }
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int sum = 0;
        for(int i=0; i<(int)nums.size(); i++) {
            sum += nums[i];
        }
        if(sum%4) return false;

        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> sums(4, 0);
        return dfs(nums, sums, 0, sum/4);
    }
};