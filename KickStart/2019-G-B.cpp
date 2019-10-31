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

int n;
ll m;
ll A[10024];

ll solve() {
    int ones[64], zeros[64];
    for(int i=0; i<64; i++) {
        ones[i] = 0;
        zeros[i] = n;
    }
    for(int i=0; i<n; i++) {
        int j=0;
        ll t = A[i];
        while(t) {
            if(t & 1) ones[j]++, zeros[j]--;
            t /= 2;
            j++;
        }
    }
    ll f[64];
    f[0] = 1LL * min(zeros[0], ones[0]);
    for(int i=1; i<51; i++) {            // must test up to 53 will zeros[i] * (1LL << i) may cause overflow.
        f[i] = f[i-1] + 1LL * min(zeros[i], ones[i]) * (1LL << i);
    }
    if(f[50] > m) return -1;
    ll ans = 0LL, sum = 0LL;
    for(int i=50; i>0; i--) {
        if(sum + f[i-1] + 1LL * zeros[i] * (1LL << i) <= m) {
            ans |= (1LL << i);
            sum += 1LL * zeros[i] * (1LL << i);
        } else {
            sum += 1LL * ones[i] * (1LL << i);
        }
    }
    if(sum + zeros[0] <= m) ans += 1;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	int t, kase = 0;
	cin >> t;
	while(t--) {
        cin >> n >> m;
        REP(i, 0, n) cin >> A[i];
        ll ans = solve();
        printf("Case #%d: %lld\n", ++kase, ans);
        ll sums = 0LL;
        REP(i, 0, n) {
            sums += A[i] ^ ans;
        }
        if(sums > m) {
            cout << "failed";
        }
	}
	return 0;
}

