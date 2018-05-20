class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int r = matrix.size();
        int c = matrix[0].size();
        queue<pair<int, pair<int, int> > > q;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(matrix[i][j]) matrix[i][j] = 10000;
                else q.push(make_pair(i, make_pair(j, 0)));
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second.first;
            int d = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++){
                int tr = x + dr[i], tc = y + dc[i];
                if(tr>=0 && tr<r && tc>=0 && tc<c && matrix[tr][tc] > d+1) {
                    q.push(make_pair(tr, make_pair(tc, d+1)));
                    matrix[tr][tc] = d+1;
                }
            }
        }
        return matrix;
    }
};