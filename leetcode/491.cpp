class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();
        map<string, int> mp;
        vector<vector<int> > ret;
        for(int i=1; i<(1 << n); i++){
            int c = 0;
            vector<int> v;
            string s;
            for(int j=0; j<n; j++){
                if(i&(1<<j) && (v.size()==0 || nums[j] >= v[c-1])){
                    c++;
                    v.push_back(nums[j]);
                    s+= to_string(nums[j])+"|";
                }
            }
            if(c >= 2 && mp.find(s) == mp.end()){
                ret.push_back(v);
                mp[s] = 1;
            }
        }
        return ret;
    }
    
};



class Solution {
public:
    void dfs(vector<int>& nums, int n, int start, vector<int>& out, vector<vector<int>>& res)
    {
        if(out.size() > 1)
        {
            res.push_back(out);
        }
        if(start == n)return;
        set<int> visited;
        for(int i = start; i < n; ++i)
        {
            if((out.empty() || nums[i] >= out.back()) && visited.count(nums[i]) == 0)
            {
                out.push_back(nums[i]);
                visited.insert(nums[i]);
                dfs(nums, n, i+1, out, res);
                out.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> out;
        dfs(nums, nums.size(), 0, out, res);
        //vector<vector<int>> vres(res.begin(), res.end());
        
        return res;
    }
};