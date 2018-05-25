class Solution {
public:
    map<char, string> mp;
    int n;
    string s;
    vector<string> letterCombinations(string digits) {
        
        vector<string> ret;
        n = digits.size();
        if(n == 0) return ret;
        s = digits;
        mp['1'] = "";
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        dfs(0, ret, "");
        return ret;
    }
    void dfs(int d, vector<string>& vs, string ts){
        if(d == n) {
            vs.push_back(ts);
            return;
        }
        // cout << d << " " << n << endl;
        for(int i=0; i<mp[s[d]].length(); i++){
            dfs(d+1, vs, ts+mp[s[d]][i]);
        }
    }
};