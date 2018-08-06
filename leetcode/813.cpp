class Solution {
public:
    double mem[200][200];
    double largestSumOfAverages(vector<int>& A, int k) {
        double cur = 0;
        memset(mem, 0, sizeof(mem));
        for(int i=0; i<A.size(); i++) {
            cur += A[i];
            mem[i+1][1] = cur/(i+1);
        }
        return helper(A, A.size(), k);
    }
    double helper(vector<int>& a, int n, int k) {
        if(mem[n][k] > 0) return mem[n][k];
        if(n < k) return 0;
        double cur = 0;
        for(int i=n-1; i>0; i--) {
            cur += a[i];
            mem[n][k] = max(mem[n][k], helper(a, i, k-1) + cur/(n-i));
        }
        return mem[n][k];
    }
};