class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int ret = 1;
        for(int i = 2; i * i < 2 * N; i++){
            if((N - i*(i-1)/2)%i == 0) ret++;
        }
        return ret;
    }
};
/*
x + (x+1) + ... + (x+k) = kx + (1+k)*k/2 = N;
kx = N-(1+k)*k/2 > 0 
k*(k+1) < 2*N
*/