class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ss = 0, ts = 0;
        bool flag;
        for(; ss<s.length(); ss++){
            flag = false;
            for(; ts<t.length(); ts++){
                if(t[ts] == s[ss]) {
                    flag = true;
                    ts++;
                    break;
                }
            }
            // cout << ss << " " << ts << " " << flag << endl;
            if(!flag) return false;
        }
        return true;
    }
};