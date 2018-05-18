class Solution {
public:
    int vist[3000];     // notice : this array size can't be small... cause the string may be long
    int numDecodings(string s) {
        if(s[0] == '0') return 0;
        cout << s.length() << endl;
        memset(vist, 0, sizeof(vist));
        return helper(s, 0);
    }
    int helper(string s, int pos){
        if(s[0] == '0') return 0;
        if(s.length() == 0) return 1;
        if(s.length() == 1) return 1;
        if(vist[pos] != 0) return vist[pos];
        string subs = s.substr(0, 2);
        if(stoi(subs) <= 26){
            int t1 = helper(s.substr(1), pos+1);
            int t2 = helper(s.substr(2), pos+2);
            vist[pos+1] = t1;
            vist[pos+2] = t2;
            return t1 + t2;
        }else{
            int t1 = helper(s.substr(1), pos+1);
            vist[pos+1] = t1;
            return t1;
        }
    }
};