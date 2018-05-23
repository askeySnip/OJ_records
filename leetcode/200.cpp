class Solution {
public:
    int vist[500][500];
    vector<vector<char> > g;
    int r, c;
    int dr[4] = {1, -1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        memset(vist, 0, sizeof(vist));
        g = grid;
        int ret = 0;
        r = grid.size();
        c = grid[0].size();
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(grid[i][j] == '1' && vist[i][j]==0) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        return ret;
    }
    void dfs(int i, int j){
        vist[i][j] = 1;
        for(int k=0; k<4; k++){
            int tr = i+dr[k], tc = j+dc[k];
            if(tr>=0 && tr<r && tc>=0 && tc<c && !vist[tr][tc] && g[tr][tc] == '1') dfs(tr, tc);
        }
    }
};