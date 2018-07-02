class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int ns = flowerbed.size();
        for(int i=0; i<ns; i++){
            if(!i && !flowerbed[0] && !flowerbed[1]) n--, flowerbed[0]=1;
            else if(i==ns-1 && !flowerbed[i-1] && !flowerbed[i]) n--;
            else{
                if(!flowerbed[i-1] && !flowerbed[i] && !flowerbed[i+1]) n--, flowerbed[i]=1;
            }
        }
        return n<=0;
    }
};