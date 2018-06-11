class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int c = 0;
        for(int i=0; i<k; i++){
            int last = nums[i];
            int ti = i+k;
            while((ti)%n != i){
                int t = nums[ti%n];
                nums[ti%n] = last;
                last = t;
                // cout << nums[ti%n] << " " << ti << " " << last << endl;
                c++;
                ti+=k;
            }
            nums[i] = last;
            c++;
            if(c == n) break;
        }
    }
};