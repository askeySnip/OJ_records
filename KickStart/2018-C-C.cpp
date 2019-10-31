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
int x[1000024];
int y[1000024];
int a[1000024];
ll s[1000024];
ll my_pow(ll base, int ex) {
    if(ex == 1) return base;
    if(ex%2 == 0) {
        return my_pow((base * base)%mod, ex/2);
    } else {
        return (my_pow(base, ex-1) * base)%mod;
    }
}

int solve() {
    int ans = 0;
    s[0] = 0;
    for(int i=0; i<n; i++) {
        s[0] += (1LL * a[i] * (n-i))%mod;
        s[0] %= mod;
    }
    for(int i=1; i<n; i++) {
        s[i] = s[i-1] - (1LL * a[i-1] * (n-i+1))%mod;
        s[i] = (s[i] + mod) % mod;
    }
    ans += (s[0] * k) % mod;
    ans %= mod;
    for(int i=1; i<n; i++) {
        ll tmp = my_pow(i+1, k+1) - (i+1);
        tmp = tmp * my_pow(i, mod-2);
        tmp %= mod;
        ans += (s[i] * tmp)%mod;
        ans %= mod;
    }
    return ans;
}

int main() {
    int t, kase = 0;
    scanf("%d", &t);
    int x1, y1, c, d, e1, e2, f;
    while(t--) {
        scanf("%d%d", &n, &k);
        scanf("%d%d%d%d%d%d%d", &x1, &y1, &c, &d, &e1, &e2, &f);
        x[0] = x1, y[0] = y1;
        a[0] = (x1 + y1) % f;
        REP(i, 1, n) {
            x[i] = (1LL * c * x[i-1] + 1LL * d * y[i-1] + e1) % f;
            y[i] = (1LL * d * x[i-1] + 1LL * c * y[i-1] + e2) % f;
            a[i] = (x[i] + y[i]) % f;
        }
        printf("Case #%d: %d\n", ++kase, solve());
    }
	return 0;
}

