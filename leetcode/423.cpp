class Solution {
public:
    string originalDigits(string s) {
        vector<int> letters(26, 0);
        for(int i=0; i<s.length(); i++){
            letters[s[i]-'a']++;
        }
        string ts;
        int c;
        vector<int> digits;
        if(letters['z'-'a']){
            c = letters['z'-'a'];
            letters['z'-'a'] = 0;
            letters['e'-'a'] -= c;
            letters['r'-'a'] -= c;
            letters['o'-'a'] -= c;
            for(int i=0; i<c; i++) digits.push_back(0);
        }
        
        if(letters['w'-'a']){
            ts = "two";
            c = letters['w'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(2);
        }
        
        if(letters['u'-'a']){
            ts = "four";
            c = letters['u'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(4);
        }
        
        if(letters['x'-'a']){
            ts = "six";
            c = letters['x'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(6);
        }
        
        if(letters['g'-'a']){
            ts = "eight";
            c = letters['g'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(8);
        }
        
        if(letters['o'-'a']){
            ts = "one";
            c = letters['o'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(1);
        }
        
        if(letters['t'-'a']){
            ts = "three";
            c = letters['t'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(3);
        }
        
        if(letters['f'-'a']){
            ts = "five";
            c = letters['f'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(5);
        }
        if(letters['v'-'a']){
            ts = "seven";
            c = letters['v'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(7);
        }
        if(letters['i'-'a']){
            ts = "nine";
            c = letters['i'-'a'];
            for(int i=0; i<ts.length(); i++){
                letters[ts[i]-'a'] -= c;
            }
            for(int i=0; i<c; i++) digits.push_back(9);
        }
        ts = "";
        sort(digits.begin(), digits.end());
        for(int i=0; i<digits.size(); i++){
            ts += to_string(digits[i]);
        }
        return ts;
    }
};