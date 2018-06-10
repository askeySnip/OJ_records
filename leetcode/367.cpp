class Solution {
public:
    bool isPerfectSquare(int num) {
        double h=num*1.0, l=0.0;
        double mid;
        while(h - l > 0.1){
            mid = (h+l)/2;
            if(mid*mid == num) break;
            if(mid*mid>num) h = mid;
            else l = mid;
        }
        for(int i=mid-1; i<mid+1; i++){
            if(i*i ==num) return true;
        }
        return false;
    }
};