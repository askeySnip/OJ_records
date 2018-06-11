class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int r = A.size(), c = A[0].size();
        for(int i=0; i<r; i++){
            int s=0, e=c-1;
            while(s<e){
                int t = A[i][s];
                A[i][s] = A[i][e];
                A[i][e] = t;
                s++; e--;
            }
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                A[i][j] = 1 - A[i][j];
            }
        }
        return A;
    }
};