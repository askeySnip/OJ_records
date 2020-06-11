/*
 * @lc app=leetcode id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

// @lc code=start
class Solution {
public:
    int f[11][52][52];
    int r, c;
    const int mod = 1e9+7;
    int ways(vector<string>& pizza, int k) {
        r = pizza.size(), c = pizza[0].length();
        memset(f, 0, sizeof f);
        return helper(pizza, 0, 0, k);
    }
    int helper(vector<string>& pizza, int tr, int tc, int k) {
        if(tr >= r || tc >= c) return 0;
        if(k == 1) {
            for(int i=tr; i<r; i++) {
                for(int j=tc; j<c; j++) {
                    if(pizza[i][j] == 'A') return 1;
                }
            }
            return 0;
        }
        if(f[k][tr][tc]) return f[k][tr][tc];
        bool flag = false;
        int& res = f[k][tr][tc];
        for(int i=tr; i<r-1; i++) {
            if(!flag) {
                for(int j=tc; j<c; j++) {
                    if(pizza[i][j] == 'A') {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) {
                res = (res + helper(pizza, i+1, tc, k-1)) % mod;
            }
        }
        flag = false;
        for(int i=tc; i<c-1; i++) {
            if(!flag) {
                for(int j=tr; j<r; j++) {
                    if(pizza[j][i] == 'A') {
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) {
                res = (res + helper(pizza, tr, i+1, k-1)) % mod;
            }
        }
        return res;
    }
};
// @lc code=end

