class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int f, b;
        map<int, int> mp;
        for(int i=0; i<fronts.size(); i++){
            f = fronts[i], b = backs[i];
            mp[f]++;
            mp[b]++;
        }
        for(int i=0; i<fronts.size(); i++){
            if(fronts[i] == backs[i]){
                mp[fronts[i]] = 0;
            }
        }
        for(auto it = mp.begin(); it!= mp.end(); it++){
            if(it->second) return it->first;
        }
        return 0;
    }
};