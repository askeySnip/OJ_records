class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int>& v, vector<int>& nums, int cur){
        for(int k=cur; k<nums.size(); k++){
            if(k > 0 && nums[k] == nums[k-1]) continue;
            int l = k;
            while(l<nums.size() && nums[k]==nums[l]) l++;
            for(int i=k; i<l; i++){
                v.push_back(nums[k]);
                ret.push_back(v);
                dfs(v, nums, l);
            }
            for(int i=k; i<l; i++){
                v.pop_back();
            }
        }
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        ret.push_back(v);
        dfs(v, nums, 0);
        return ret;
    }
};