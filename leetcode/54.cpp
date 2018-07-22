class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if(matrix.size() == 0) return ans;
        // ans.resize(matrix.size() * matrix[0].size());
        int lr = 0, lc = 0, hr = matrix.size()-1, hc = matrix[0].size()-1;
        // int c = 0;
        while(1){
            for(int i=lc; i<=hc; i++){
                ans.push_back(matrix[lr][i]);
            }
            lr++;
            if(lr > hr) break;
            for(int i=lr; i<=hr; i++){
                ans.push_back(matrix[i][hc]);
            }
            hc--;
            if(lc > hc) break;
            for(int i=hc; i>=lc; i--){
                ans.push_back(matrix[hr][i]);
            }
            hr--;
            if(lr > hr) break;
            for(int i=hr; i>=lr; i--){
                ans.push_back(matrix[i][lc]);
            }
            lc++;
            if(lc > hc) break;
        }
        return ans;
    }
};