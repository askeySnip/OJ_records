class Solution {
public:
    int cac(int n){
        if(n < 3) return 0;
        return (n-2)*(n-1)/2;
    }
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3) return 0;
        int c = 2, d = A[1]-A[0];
        int ans = 0;
        for(int i=2; i<A.size(); i++){
            if(A[i]-A[i-1] == d) c++;
            else {
                d = A[i]-A[i-1];
                ans += cac(c);
                c = 2;
            }
        }
        ans += cac(c);
        return ans;
    }
};