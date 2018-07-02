class Solution {
public:
    bool check(int n, int t, int buckets){
        return buckets <= pow(n, t);
    }
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int t = minutesToTest / minutesToDie;
        if(t+1 >= buckets && buckets != 1) return 1;
        buckets/=2;
        int l = 0, h = buckets, mid;
        while(l < h - 1){
            mid = (l+h)/2;
            if(check(mid, t, buckets)) h = mid;
            else l = mid;
        }
        for(int i=l; i<=h; i++){
            if(check(i, t, buckets)) return i;
        }
    }
};