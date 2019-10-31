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

int n, k;
int a[110];

int solve() {
    set<int> us;
    for(int i=0; i<n; i++) {
        us.insert(a[i]);
    }
    vi nums(us.begin(), us.end());
    int t = nums.size();
    vector<vector<vi>> f(n+1, vector<vi>(k+1, vi(t, inf)));
    vector<vi> minf(n+1, vi(k+1, inf));
    for(int i=0; i<t; i++) {
        if(nums[i] != a[0]) {
            f[1][0][i] = 1;
        } else {
            f[1][0][i] = 0;
            minf[1][0] = 0;
        }
    }
    for(int i=2; i<=n; i++) {
        for(int j=0; j<=min(k, i-1); j++) {
            for(int m=0; m<t; m++) {
                f[i][j][m] = f[i-1][j][m];
                if(j > 0) f[i][j][m] = min(f[i-1][j][m], minf[i-1][j-1]);
                if(a[i-1] != nums[m]) f[i][j][m]++;
                if(f[i][j][m] < minf[i][j]) minf[i][j] = f[i][j][m];
            }
        }
    }
    int ans = inf;
    for(int j=0; j<=k; j++) {
        for(int m=0; m<t; m++) {
            ans = min(ans, f[n][j][m]);
        }
    }
    return ans;
}

int main() {
	int t, kase = 0;
	scanf("%d", &t);
	while(t--) {
        scanf("%d %d", &n, &k);
        REP(i, 0, n) scanf("%d", &a[i]);
        printf("Case #%d: %d\n", ++kase, solve());
	}
	return 0;
}

