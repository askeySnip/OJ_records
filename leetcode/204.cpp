class Solution {
public:
    int countPrimes(int n) {
        bool *vist= (bool*)malloc(sizeof(bool)*n);
        for(int i=0; i<n; i++){
            vist[i] = 0;
        }
        int c = 0;
        for(int i=2; i<n; i++){
            if(!vist[i]){
                vist[i] = 1;
                c++;
                for(int j=2; j*i<n; j++) vist[j*i]=1;
            }
        }
        // free(vist); //in real programming, this may be good to add, but in leetcode, this may cause slow
        return c;
    }
};