class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0;
        unordered_map<int, int> mp;
        int c = 0;
        mp[0] = 0;
        int ret = 0;
        for(int i=0; i<n; i++){
            if(nums[i]) c++;
            else c--;
            if(mp.find(c) != mp.end()){
                ret = max(ret, i-mp[c]+1);
            }else{
                mp[c] = i+1;
            }
        }
        return ret;
    }
};