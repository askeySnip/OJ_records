class Solution {
public:
    bool valid_dig(string& s){
        if(s.length() == 1) return true;
        bool dec = false;
        for(int i=0; i<s.length(); i++){
            if(s[i] == '.') dec = true;
            if(s[0] == '0' && s[1] != '.') return false;
        }
        if(dec && s[s.length()-1] == '0') return false;
        return true;
    }
    void deal(string& s, vector<string>& vs){
        for(int i=1; i<s.length(); i++){
            string s1 = s.substr(0, i) + "." + s.substr(i);
            if(valid_dig(s1)) vs.push_back(s1);
        }
        if(valid_dig(s)) vs.push_back(s);
    }
    vector<string> ambiguousCoordinates(string S) {
        vector<string> ans;
        int dlen = S.length()-2;
        for(int i=1; i<S.length()-2; i++){
            string s1 = S.substr(1, i);
            string s2 = S.substr(i+1, dlen-i);
            vector<string> vs1, vs2;
            deal(s1, vs1);
            deal(s2, vs2);
            if(vs1.size() && vs2.size()){
                for(int j=0; j<vs1.size(); j++){
                    for(int k=0; k<vs2.size(); k++){
                        ans.push_back("(" + vs1[j] + ", " + vs2[k] + ")");
                    }
                }
            }
        }
        return ans;
    }
};