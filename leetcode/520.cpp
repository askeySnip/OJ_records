class Solution {
public:
    inline bool isCap(char c) {
        return (c>='A' && c<='Z');
    }
    bool detectCapitalUse(string word) {
        if(word.length() == 0) return false;
        int c = 0;
        for(int i=0; i<word.length(); i++) {
            if(isCap(word[i])) c++;
        }
        if(c == word.length() || c == 0) return true;
        if(c == 1 && isCap(word[0])) return true;
        return false;
    }
};