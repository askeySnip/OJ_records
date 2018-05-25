class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        int l[32];
        memset(l, 0, sizeof(l));
        for(int i=0; i<n; i++){
            int& t = nums[i];
            for(int j=0; j<32; j++){
                if(t & (1<<j)) l[j]++;
            }
        }
        int thd = 0;
        for(int i=0; i<32; i++){
            if(l[i]==0 || l[i] == n) continue;
            thd += l[i] * (n-l[i]);
        }
        return thd;
    }
};