class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int lines = 1, units = 0;
        int len = S.length();
        for(int i=0; i<len; i++){
            units += widths[S[i]-'a'];
            if(units > 100) {
                units = widths[S[i]-'a'];
                lines++;
            }
        }
        vector<int> ret;
        ret.push_back(lines);
        ret.push_back(units);
        return ret;
    }
};