class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool flag = true;
        for(int i=1; i<A.size(); i++) {
            if(A[i] > A[i-1]) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
        flag = true;
        for(int i=1; i<A.size(); i++) {
            if(A[i] < A[i-1]) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
        return false;
    }
};