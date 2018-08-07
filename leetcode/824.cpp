class Solution {
public:
    bool check(char c) {
        c = (char)tolower(c);
        if(c == 'a' || c == 'o' || c == 'e' || c == 'i' || c == 'u') return true;
        return false;
    }
    string change2GL(string s, int c) {
        if(check(s[0])) {
            s += "ma";
            for(int i=0; i<c; i++) s+='a';
            return s;
        } else {
            string ret= "";
            ret += s.substr(1);
            ret += s[0]; ret += "ma";
            for(int i=0; i<c; i++) ret += 'a';
            // // cout << ret << endl;
            return ret;
        }
    }
    string toGoatLatin(string s) {
        string ret;
        string::size_type n, t = 0;
        int c = 1;
        while((n = s.find(' ', t)) != string::npos) {
            // cout << s.substr(t, n-t) << endl;
            ret += change2GL(s.substr(t, n-t), c) + " ";
            // cout << ret<< endl;
            t = n+1;
            c++;
        }
        ret += change2GL(s.substr(t), c);
        return ret;
    }
};