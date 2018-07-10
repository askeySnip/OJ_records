class Solution {
public:
    int numRabbits(vector<int>& answers) {
        if(answers.size()==0) return 0;
        sort(answers.begin(), answers.end());
        vector<int> m(1000, 0);
        int ans = 0;
        for(int i=0; i<answers.size(); i++){
            if(m[answers[i]]++ == 0) ans += answers[i]+1;
            if(m[answers[i]] > answers[i]) m[answers[i]] = 0;
        }
        return ans;
    }
};