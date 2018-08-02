class Solution {
public:
    bool check(int m, vector<int>& piles, int& h) {
        if(m == 0) return false;
        int c = 0;
        for(int i=0; i<piles.size(); i++) {
            c += piles[i]/m;
            if(piles[i]%m) c++;
        }
        return c <= h;
    }
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 0, h = 0, mid;
        for(int i=0; i<piles.size(); i++) {
            h = max(h, piles[i]);
        }
        while(l < h) {
            mid = (l + h) / 2;
            if(check(mid, piles, H)) h = mid;
            else l = mid + 1;
        }
        return h;
    }
};


class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int ans = 0;
        long long sum = 0;
        
        int left =  1;
        int right = *max_element(piles.begin(), piles.end());
        
        ans = right;
        if(piles.size() == H){
            return ans;
        }
        
        sum = accumulate(piles.begin(), piles.end(), sum);
        if(H >= sum){
            return 1;
        }
        
        int tmpTime = 0,mid;
        while(left <= right){
            mid = ((right - left)>>1) + left;
            tmpTime = 0;
            for(int pile : piles){
                tmpTime = tmpTime + ( (pile + mid - 1)/mid);
            }
            if(tmpTime > H){
                left = mid + 1;
            } else if(tmpTime <= H){
                ans = min(ans, mid);
                right = mid - 1;
            }
            
        }
        
        return ans;
    }
};