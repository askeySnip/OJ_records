class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int l=1; l<=len/2; l++){
            if(len%l) continue;
            string r = s.substr(0, l);
            string p;
            for(int i=0; i<len/l; i++){
                p+=r;
            }
            if(p == s) return true;
        }
        return false;
    }
};