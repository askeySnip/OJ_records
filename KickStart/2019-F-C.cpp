/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
const int inf = 1e9;
const int mod = 1e9+7;

int v;
int b[100024];
vi e[100024];
ll mem[4][100024];

// p : be light by parent, q : whether put a light on k
ll solve(int k, bool p, bool q, int parent) {
    //cout << k << " " << p << " " << q << "start" << endl;
    if(mem[p+q*2][k] != -1) return mem[p+q*2][k];
    ll ret = 0;
    if(q) {
        for(int i=0; i<e[k].size(); i++) {
            if(e[k][i] == parent) continue;
            ret += max(solve(e[k][i], 1, 0, k), solve(e[k][i], 1, 1, k));
        }
        ret += b[k];
    } else if(p) {
        for(int i=0; i<e[k].size(); i++) {
            if(e[k][i] == parent) continue;
            ret += max(solve(e[k][i], 0, 0, k), solve(e[k][i], 0, 1, k));
        }
        ret += b[k];
    } else {
        vector<vector<ll>> dp(2, vector<ll>(e[k].size()+1, 0));
        dp[1][0] = -inf;
        for(int i=1; i<=e[k].size(); i++) {
            if(e[k][i-1] == parent) {
                dp[0][i] = dp[0][i-1];
                dp[1][i] = dp[1][i-1];
                continue;
            }
            ll t1 = solve(e[k][i-1], 0, 1, k), t2 = solve(e[k][i-1], 0, 0, k);
            dp[0][i] = dp[0][i-1] + t2;
            dp[1][i] = max(dp[1][i-1] + max(t2, t1), dp[0][i-1] + t1);
        }
        ret = max(dp[0][e[k].size()], dp[1][e[k].size()] + b[k]);
    }
    //cout << k << " " << p << " " << q << " " << ret << " " << "end" << endl;
    return mem[p+q*2][k] = ret;
}

int main() {
	int t, kase = 0;
	scanf("%d", &t);
	while(t--) {
        scanf("%d", &v);
        REP(i, 0, v+1) e[i].clear();
        REP(i, 1, v+1) scanf("%d", &b[i]);
        int x, y;
        REP(i, 0, v-1) {
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        memset(mem, -1, sizeof mem);
        printf("Case #%d: %lld\n", ++kase, max(solve(1, 0, 0, -1), solve(1, 0, 1, -1)));
	}
	return 0;
}

