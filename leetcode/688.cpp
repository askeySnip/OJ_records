class Solution {
public:
    int n, k;
    int dr[8] = {2, 2, 1, 1, -1, -1, -2, -2};
    int dc[8] = {1, -1, 2, -2, 2, -2, 1, -1};
    double m[35][35][105];
    double knightProbability(int N, int K, int r, int c) {
        n = N;
        k = K;
        memset(m, 0, sizeof(m));
        return helper(r, c, 0);
    }
    double cmp(int d){
        double ret = 1.0;
        for(int i=0; i<d; i++){
            ret *= 0.125;
        }
        return ret;
    }
    bool check(int r, int c){
        return (r>=0 && r<n && c>=0 && c<n);
    }
    double helper(int r, int c, int d){
        if(check(r, c)){
            if(d == k) return cmp(d);
            if(m[r][c][d]!=0) return m[r][c][d]; 
            double ret = 0.0;
            for(int i=0; i<8; i++){
                double t = helper(r+dr[i], c+dc[i], d+1);
                if(t) m[r+dr[i]][c+dc[i]][d+1] = t;
                ret += t;
            }
            return ret;
        }
        return 0;
    }
};