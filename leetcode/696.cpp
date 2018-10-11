class Solution {
public:
    int countBinarySubstrings(string s) {
        int last = 0, count = 1;
        int i=0;
        int ans = 0;
        while(i<s.length()) {
            while(i<s.length()-1 && s[i] == s[i+1]) {
                count++;
                i++;
            }
            ans += min(last, count);
            last = count; count = 1;
            i++;
        }
        return ans;
    }
};