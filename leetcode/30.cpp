class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ret;
        unordered_map<string, int> counts;
        for(string word : words){
            counts[word]++;
        }
        // the little notice place is to check whether s is null and whether words is null
        int n = s.length();
        if(n == 0) return ret;
        int num = words.size();
        if(num == 0) return ret;
        int len = words[0].length();
        for(int i=0; i<n-num*len+1; i++){
            unordered_map<string, int> seen;
            int j = 0;
            for(; j<num; j++){
                string word = s.substr(i+j*len, len);
                if(counts.find(word)!=counts.end()){
                    seen[word]++;`
                    if(seen[word]>counts[word]) break;
                }else{
                    break;
                }
            }
            if(j == num) ret.push_back(i);
        }
        return ret;
    }
};