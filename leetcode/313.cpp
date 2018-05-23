class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n == 1) return 1;
        int len = primes.size();
        vector<int> l(len, 0);
        vector<int> un;
        un.push_back(1);
        int c = 1;
        while(c != n){
            int m = INT_MAX;
            
            for(int i=0; i<len; i++){
                int t = primes[i] * un[l[i]];
                // cout << t << " " << m << endl;
                m = min(m, t);
            }
            for(int i=0; i<len; i++){
                if(primes[i] * un[l[i]] == m) l[i]++;
            }
            // cout << m << endl;
            c++;
            un.push_back(m);
        }
        return un[n-1];
    }
};