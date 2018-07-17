class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> > vii(n, vector<int>(n, 0));
        int lr = 0, lc = 0, hr = n-1, hc = n-1, c = 1;
        while(lr <= hr && lc <= hc){
            int i;
            for(i=lc; i<=hc; i++){
                vii[lr][i] = c++;
            }
            lr++;
            for(i=lr; i<=hr; i++){
                vii[i][hc] = c++;
            }
            hc--;
            for(i=hc; i>=lc; i--){
                vii[hr][i] = c++;
            }
            hr--;
            for(i=hr; i>=lr; i--){
                vii[i][lc] = c++;
            }
            lc++;
        }
        return vii;
    }
};