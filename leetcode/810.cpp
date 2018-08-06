class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int xo = 0;
        for(int i=0; i<nums.size(); i++) xo ^= nums[i];
        return xo == 0 || nums.size()%2 == 0;
    }
};