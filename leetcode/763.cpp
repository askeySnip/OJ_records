class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        vector<int> vist(26, 0);
        int left = 0, right = 0;
        for(int i=0; i<S.length(); i++){
            if(vist[S[i]-'a']) continue;
            if(i > right) {
                ans.push_back(right - left + 1);
                left = i;
                right = i;
            }
            auto pos = S.rfind(S[i]);
            if(pos == string::npos) continue;
            right = max(right, (int)pos);
            vist[S[i]-'a'] = 1;
        }
        ans.push_back(right-left+1);
        return ans;
    }
};