class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;
        int ans = 0;
        for(int i=1; i<n-1;){
            if(A[i] <= A[i+1]) {i++; continue;}
            int j = i;
            while(j>=1 && A[j]>A[j-1]) j--;
            int l = i-j;
            j = i;
            while(j<n-1 && A[j]>A[j+1]) j++;
            int r = j-i;
            if(l>0 && r>0){
                ans = max(ans, l+r+1);
            }
            i = j;
        }
        return ans;   
    }
};