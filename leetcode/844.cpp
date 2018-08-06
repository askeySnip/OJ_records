class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return get_str(S) == get_str(T);
    }
    string get_str(string s) {
        string ret;
        int count = 0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '#') count++;
            else {
                if(count > 0) count--;
                else ret = s[i]+ret;
            }
        }
        return ret;
    }
};