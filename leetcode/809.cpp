class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int ret = 0;
        if(words.size() == 0) return 0;
        for(int i=0; i<words.size(); i++){
            cout << i << endl;
            if(check(S, words[i])) ret++;
        }
        return ret;
    }
    bool check(string s, string word){
        if(s == word) return true;
        int a=0, b=0;
        int lens = s.length();
        int lenw = word.length();
        if(lens == 0 || lenw == 0) return false;
        while(a < lens && b < lenw){
            int t = a;
            int c = 1;
            while(t<lens-1 && s[t] == s[t+1]) c++, t++;
            // cout << t << " " << c << endl;
            int cw = 1, tw = b;
            while(tw < lenw-1 && word[tw] == word[tw+1]) cw++, tw++;
            // cout << tw << " " << cw << endl;
            if(cw > c) return false;
            if(c > 2 && s[a] == word[b]) {
                a = t+1;
                b = tw+1;
            }else{
                if(s[a]!=word[b]) return false;
                a++;
                b++;
            }
            // cout << a << " " << b << " " << c << endl;
        }
        if(a == lens && b == lenw) return true;
        else return false;
    }
};