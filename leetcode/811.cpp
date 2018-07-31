class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> mp;
        for(int i=0; i<cpdomains.size(); i++) {
            int j = 0;
            string& domain = cpdomains[i];
            string::size_type n = domain.find(' ');
            int t = stoi(domain.substr(0, n));
            while(n != string::npos) {
                mp[domain.substr(n+1)] += t;
                n = domain.find('.', n+1);
            }
        }
        vector<string> ret;
        for(auto it=mp.begin(); it!=mp.end(); it++) {
            ret.push_back(to_string(it->second) + " " + it->first);
        }
        return ret;
    }
};