class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;
        int endtime = timeSeries[0] + duration;
        int minus = 0;
        for(int i=1; i<timeSeries.size(); i++){
            if(timeSeries[i] <= endtime) {
                endtime = timeSeries[i] + duration;
            }else{
                minus += timeSeries[i] - endtime;
                endtime = timeSeries[i] + duration;
            }
        }
        return endtime-timeSeries[0]-minus;
    }
};