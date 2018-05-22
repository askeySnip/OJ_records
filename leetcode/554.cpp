class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int r = wall.size();
        map<int, int> mp;
        int count = 0;
        for(int i=0; i<r; i++){
            vector<int>& rw = wall[i];
            int len = 0;
            for(int j=0; j<rw.size()-1; j++){
                len += rw[j];
                mp[len]++;
                count = max(mp[len], count);
            }
        }
        return r - count;
    }
};