class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, int> ump;
        for(int i=0; i<J.length(); i++){
            ump[J[i]] = 1;
        }
        int ans = 0;
        for(int i=0; i<S.length(); i++){
            if(ump.find(S[i]) != ump.end()) ans++;
        }
        return ans;
    }
};