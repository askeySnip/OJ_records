class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double m[101][101] = {0.0};
        m[0][0] = poured;
        for(int i=0; i<100; i++){
            for(int j=0; j<=i; j++){
                if(m[i][j] > 1){
                    m[i+1][j] += (m[i][j]-1)/2.0;
                    m[i+1][j+1] += (m[i][j]-1)/2.0;
                    m[i][j] = 1;
                }
            }
        }
        return m[query_row][query_glass];
    }
};