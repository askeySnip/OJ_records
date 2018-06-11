class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        if(n == 0) return 0;
        int s = A[0], t = 0;
        for(int i=1; i<n; i++) {
            s += A[i];
            t += i*A[i];
        }
        int ans = t;
        for(int i=n-1; i>0; i--){
            t = t - n*A[i] + s;
            ans = max(t, ans);
        }
        return ans;
    }
};