class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<vector<int> > pos(1003, vector<int>(26, -1));
        for(int i=0; i<s.length(); i++) {
            for(int j=0; j<=i; j++) {
                if(pos[j][s[i]-'a'] != -1) continue;
                pos[j][s[i]-'a'] = i;
            }
        }
        sort(d.begin(), d.end());
        string ret;
        for(int i=0; i<d.size(); i++) {
            string& ds = d[i];
            int p = 0;
            int j = 0;
            while(p<s.length() && j < ds.length() && pos[p][ds[j]-'a'] != -1) {
                p = pos[p][ds[j]-'a'] + 1;
                j++;
            }
            if(j == ds.length()) {
                if(ret.length() < ds.length()) ret = ds;
            }
        }
        return ret;
    }
};