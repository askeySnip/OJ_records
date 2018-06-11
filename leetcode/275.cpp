class Solution {
public:
    int n;
    bool check(int m, vector<int>& citations){
        if(citations[n-m] >= m) return true;
        else return false;
    }
    int hIndex(vector<int>& citations) {
        n = citations.size();
        int h = n+1, l = 0;
        while(h-1>l){
            int mid = (h+l)/2;
            if(check(mid, citations)) l = mid;
            else h = mid;
        }
        return l;
    }
};