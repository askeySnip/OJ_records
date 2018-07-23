class Solution {
public:
    string reverseWords(string s) {
        string ret;
        int len = s.length();
        if(len == 0) return ret;
        string t;
        for(int i=len-1; i>=0; i--){
            if(s[i] == ' '){
                ret = " " + t + ret;
                t = "";
            }
            else t += s[i];
        }
        ret = t + ret;
        return ret;
    }
};