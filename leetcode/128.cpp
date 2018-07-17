class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> ump;
        for(int i: nums){
            ump[i] = 1;
        }
        int longest = 0;
        for(int i: nums){
            if(ump.find(i-1) == ump.end()){
                int current = 1;
                int t = i+1;
                while(ump.find(t) != ump.end()){
                    current++;
                    t++;
                }
                longest = max(current, longest);
            }
        }
        return longest;
    }
};