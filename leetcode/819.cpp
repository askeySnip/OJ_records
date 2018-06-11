class Solution {
public:
    string getstr(string s){
        int l = s.length();
        string ret;
        for(int i=0; i<l; i++){
            if(s[i]>='a'&&s[i]<='z') ret+=s[i];
            else if(s[i]>='A'&&s[i]<='Z') ret+=(s[i]-'A'+'a');
            else break;
        }
        return ret;
    }
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        for(int i=0; i<banned.size(); i++){
            mp[banned[i]] = 1;
        }
        unordered_map<string, int> cmp;
        int len = paragraph.length();
        int s = 0;
        for(int i=0; i<len; i++){
            if(paragraph[i] == ' '){
                string st = getstr(paragraph.substr(s, i-s));
                // cout << st << endl;
                s = i+1;
                cmp[st]++;
            }
        }
        string st = getstr(paragraph.substr(s));
        cmp[st]++;
        vector<pair<int, string> > v;
        for(auto it = cmp.begin(); it!=cmp.end(); it++){
            if(mp.find(it->first) != mp.end()) continue;
            v.push_back(make_pair(it->second, it->first));
        }
        sort(v.begin(), v.end());
        return v[v.size()-1].second;
    }
};