/*
 * @lc app=leetcode id=345 lang=cpp
 *
 * [345] Reverse Vowels of a String
 */

// @lc code=start
class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        int a = 0, b = n-1;
        while(a < b) {
            while(a < n && !isVowel(s[a])) a++;
            while(b >= 0 && !isVowel(s[b])) b--;
            if(a >= b) break;
            swap(s[a], s[b]);
            a++; b--;
        }
        return s;
    }
    bool isVowel(char c) {
        c = tolower(c);
        return (c == 'a' || c == 'o' || c == 'e' || c == 'u' || c == 'i');
    }
};
// @lc code=end

