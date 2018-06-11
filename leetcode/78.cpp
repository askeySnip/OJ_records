class Solution {
public:
    vector<vector<int> > ret;
    int n;
    void dfs(int c, vector<int>& v, vector<int>& nums){
        ret.push_back(v);
        for(int i=c+1; i<n; i++){
            v.push_back(nums[i]);
            dfs(i, v, nums);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        ret.push_back(v);
        for(int i=0; i<n; i++){
            v.push_back(nums[i]);
            dfs(i, v, nums);
            v.pop_back();
        }
        return ret;
    }
};