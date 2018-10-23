/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int ans = 0;
        int n = intervals.size();
        if(n == 0) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int last = 0;
        for(int i=1; i<n; i++) {
            if(intervals[i].start < intervals[last].end) {
                ans++;
            }else {
                last = i;
            }
        }
        return ans;
    }
    static bool cmp(Interval& a, Interval& b) {
        return (a.end == b.end) ? a.start < b.start : a.end < b.end;
    }
};