class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        nums.push_back(-1);
        int i = 0;
        int ret = 0;
        while(nums[i] == 0) i++;
        for(; i<nums.size()-1; i++) {
            // int c = 1;
            // while(nums[i] == nums[i+1]) c++, i++;
            int n = 0;
            for(int j=i+1; j<nums.size()-1; j++) {
                for(int k=j+1; k<nums.size()-1 && nums[k]-nums[j]<nums[i]; k++) {
                    n++;
                }
            }
            ret += n;
        }
        return ret;
    }
};

// a better solvetion

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count = 0, n = nums.size();
        for(int i=n-1; i>=2; i--) {
            int l = 0, r = i-1;
            while(l < r) {
                if(A[l] + A[r] > A[i]) {
                    count += r-l;
                    r--;
                }
                else l++;
            }
        }
        return count;
    }
}