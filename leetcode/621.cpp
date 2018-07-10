class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int c = 0;
        for(int i=0; i<tasks.size(); i++){
            count[tasks[i]-'A']++;
            c = max(c, count[tasks[i]-'A']);
        }
        int ans = (c-1)*(n+1);
        for(int i=0; i<26; i++){
            if(count[i] == c) ans++;
        }
        return max((int)tasks.size(), ans);
    }
};