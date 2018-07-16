class Solution {
public:
    vector<vector<int> > vv;
    bool dfs(int position, int step, vector<int>& stones){
        if(position == stones.size()-1) return true;
        if(vv[position][step] != -1) return vv[position][step];
        // int flag = 0;
        for(int i=1; i>=-1; i--){
            int t = step+i;
            for(int j=position+1; j<stones.size(); j++){
                if(stones[position] + t == stones[j] && dfs(j, t, stones)) {
                    vv[position][step] = 1;
                    return true;
                }
                if(stones[position] + t < stones[j]) break;
            }
        }
        vv[position][step] = 0;
        return false;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vv.resize(n);
        for(int i=0; i<n; i++){
            vv[i].resize(n);
            for(int j=0; j<n; j++) vv[i][j] = -1;
        }
        return dfs(0, 0, stones);
    }
};