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

int n, m;
ll jc[200010];
ll base2[100010];

ll my_pow(ll base, int e) {
    if(e == 1) return base;
    if(e%2 == 1) {
        return (my_pow(base, e-1) * base) % mod;
    } else {
        return my_pow((base * base)%mod, e/2);
    }
}

ll solve() {
    jc[0] = 1;
    for(int i=1; i<=2 * n; i++) {
        jc[i] = (jc[i-1] * i) % mod;
    }
    base2[0] = 1;
    for(int i=1; i<=m; i++) {
        base2[i] = (base2[i-1] * 2) % mod;
    }
    vector<ll> c;
    c.push_back(1);
    c.push_back(m);
    for(int i=2; i<=m; i++) {
        ll t = c.back();
        t = (t * (m-i+1)) % mod;
        t = (t * my_pow(i, mod-2)) % mod;
        c.push_back(t);
    }
    ll ans = jc[2 * n];
    // cout << ans << endl;
    for(int i=1; i<=m; i++) {
        ll t = (base2[i] * jc[2 * n - i]) % mod;
        t = (t * c[i]) % mod;
        if(i&1) ans = ans + mod - t;
        else ans += t;
        ans %= mod;
        // cout << ans << endl;
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &m);
        printf("Case #%d: %lld\n", ++kase, solve());
        //solve();
    }
	return 0;
}

