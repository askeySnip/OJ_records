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
public:
    static bool cmp(Interval& a, Interval& b){
        if(a.start != b.start) return a.start<b.start;
        return a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        if(n < 2) return intervals;
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for(int i=1; i<n; i++){
            if(intervals[i].start <= ret.back().end){
                ret.back().end = max(ret.back().end, intervals[i].end);
            }else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
};