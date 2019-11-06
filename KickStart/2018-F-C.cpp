/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

ll l, n, k;
char prefix[1024];
ll len;

bool isPal(ll f, ll t) {
  while (f < t) {
    if (prefix[f++] != prefix[t--]) return false;
  }
  return true;
}

ll P(char c) {
  if (c == '$') {
    return (isPal(0, len - 1) ? 1 : 0);
  }
  ll res = 0;
  prefix[len] = c;
  ll d = len + 1;
  for (ll i = d; i < n + 1; i++) {
    ll diff = (i + 1) / 2 - d;
    if (diff >= 0 || isPal(i - d, len)) res += (ll)pow(l, max(0LL, diff));
  }
  return res;
}

ll solve() {
  if (k <= n) {
    return k;
  }
  if (l == 1) return 0;  // l == 0 then must be k <= n;
  ll t = (ll)((n + 1) / 2 - log(k) / log(l));
  if (t < -20)
    return 0;  // cause the t is not the accurate val, so must have a loss.
  t = max(0LL, t);
  n -= t * 2;
  k -= t * 2;
  len = 0;
  while (true) {
    ll res = P('$');
    if (res <= k)
      k -= res;
    else
      return len + (t * 2);
    bool f = false;
    for (int i = 0; i < l; i++) {
      res = P('a' + i);
      if (res <= k)
        k -= res;
      else {
        prefix[len++] = ('a' + i);
        f = true;
        break;
      }
    }
    if (!f) return 0;
  }
  return 0;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld%lld%lld", &l, &n, &k);
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }
  return 0;
}
