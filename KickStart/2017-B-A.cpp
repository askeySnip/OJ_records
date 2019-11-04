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
const ll inf = 1e17;
const int mod = 1e9+7;

int n;
ll pow2[10010];
int k[10010];

ll solve() {
    ll ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            ans += (k[j] - k[i]) * pow2[j-i-1];
            ans %= mod;
        }
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    pow2[0] = 1;
    for(int i=1; i<10010; i++) {
        pow2[i] = (pow2[i-1] * 2) % mod;
    }
    while(t--) {
        scanf("%d", &n);
        REP(i, 0, n) scanf("%d", &k[i]);
        printf("Case #%d: %lld\n", ++kase, solve());
        //solve();
    }
	return 0;
}

