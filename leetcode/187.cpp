class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> mp;
        int len = s.length();
        vector<string> ans;
        for(int i=0; i<len-9; i++){
            string t = s.substr(i, 10);
            if(mp.find(t)!=mp.end() && mp[t] == 1) {
                ans.push_back(t);
            }
            mp[t]++;
        }
        return ans;
    }
};