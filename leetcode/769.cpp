class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0;
        int s = 0, m = 0, c = 0, f = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] == s) f = 1;
            m = max(m, arr[i]);
            if(f && c == m-s){
                ans++;
                m++;
                s = m;
                c = 0;
                f = 0;
            }else{
                c++;
            }
        }
        return ans;
    }
};