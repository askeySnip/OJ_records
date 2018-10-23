class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        int s = 0;
        unordered_map<string, int> ma, mb;
        for(int i=0; i<A.length(); i++) {
            if(A[i] == ' ') {
                string ts = A.substr(s, i-s);
                ma[ts]++;
                s = i+1;
            }
        }
        ma[A.substr(s)]++;
        s = 0;
        for(int i=0; i<B.length(); i++) {
            if(B[i] == ' ') {
                string ts = B.substr(s, i-s);
                mb[ts]++;
                s = i+1;
            }
        }
        mb[B.substr(s)]++;
        vector<string> vs;
        for(auto it = ma.begin(); it!=ma.end(); it++) {
            if(it->second == 1 && mb.find(it->first) == mb.end()) vs.push_back(it->first);
        }
        for(auto it=mb.begin(); it!=mb.end(); it++) {
            if(it->second == 1 && ma.find(it->first) == ma.end()) vs.push_back(it->first);
        }
        return vs;
    }
};