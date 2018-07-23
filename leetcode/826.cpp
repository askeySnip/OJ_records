class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int ans = 0;
        sort(worker.begin(), worker.end());
        vector<pair<int, int> > vp;
        for(int i=0; i<difficulty.size(); i++){
            vp.push_back(make_pair(difficulty[i], profit[i]));
        }
        sort(vp.begin(), vp.end());
        int pre = 0, prof = 0;
        for(int i=0; i<difficulty.size(); i++) {
            if(vp[i].first <= worker[pre]) {
                prof = max(vp[i].second, prof);
            }
            if(vp[i].first > worker[pre] || i == difficulty.size()-1) {
                ans += prof;
                pre++;
                i--;
                // cout << ans << " " << pre << " " << i << endl;
            }
            if(pre == worker.size()) break;
        }
        // if(pre < worker.size() && vp[difficulty.size()-1].first <= worker[pre]) ans += prof;
        return ans;
    }
};