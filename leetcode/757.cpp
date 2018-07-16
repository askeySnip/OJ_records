class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[1] == b[1]) return a[0]>b[0];
        else return a[1] < b[1];
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, p1 = -1, p2 = -1;
        for(int i=0; i<intervals.size(); i++){
            if(intervals[i][0] <= p1) continue;
            
            if(intervals[i][0] > p2){
                ans += 2;
                p2 = intervals[i][1];
                p1 = p2-1;
            }else{
                ans++;
                p1 = p2;
                p2 = intervals[i][1];
            }
        }
        return ans;
    }
};