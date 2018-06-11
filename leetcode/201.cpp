class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        int f = 1;
        while(m != n){
            m /= 2;
            n /= 2;
            f = (f<<1);
        }
        return m*f;
    }
};