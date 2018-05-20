class Solution {
public:
    string getHint(string secret, string guess) {
        int s[10], g[10];
        for(int i=0; i<10; i++) s[i]=0,g[i]=0;
        int len = secret.length();
        int c = 0;
        for(int i=0; i<len; i++){
            if(secret[i] == guess[i]) c++;
            s[secret[i]-'0']++;
            g[guess[i]-'0']++;
        }
        string ret;
        ret += to_string(c) + "A";
        int d = 0;
        for(int i=0; i<10; i++){
            d += min(s[i], g[i]);
        }
        ret += to_string(d-c) + "B";
        return ret;
    }
};