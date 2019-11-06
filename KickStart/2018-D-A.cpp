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

int n, o;
ll d;
ll x[500010];
ll s[500010];
ll prefix[500010];
multiset<ll> ms;

void solve() {
  ms.clear();
  ll ans = -1e18;
  int odds = 0, l = 1, r = 1;
  for (; l <= n; l++) {
    r = max(r, l);
    while (r <= n) {
      if (s[r] & 1) {
        if (odds < o) {
          ms.insert(prefix[r]);
          odds++;
        } else {
          break;
        }
      } else {
        ms.insert(prefix[r]);
      }
      r++;
    }
    auto it = ms.upper_bound(prefix[l - 1] + d);
    if (it != ms.begin()) {
      --it;
      ans = max(ans, *it - prefix[l - 1]);
    }
    if (l < r) {
      if (s[l] % 2 != 0) odds--;
      ms.erase(ms.find(prefix[l]));
    }
  }
  if (ans == -1e18)
    printf("IMPOSSIBLE\n");
  else
    printf("%lld\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int x1, x2, a, b, c, m, l;
  while (t--) {
    scanf("%d%d%lld", &n, &o, &d);
    scanf("%d%d%d%d%d%d%d", &x1, &x2, &a, &b, &c, &m, &l);
    x[1] = x1, x[2] = x2;
    s[1] = x1 + l, s[2] = x2 + l;
    prefix[0] = 0, prefix[1] = s[1], prefix[2] = prefix[1] + s[2];
    for (int i = 3; i <= n; i++) {
      x[i] = (1LL * a * x[i - 1] + 1LL * b * x[i - 2] + c) % m;
      s[i] = x[i] + l;
      prefix[i] = prefix[i - 1] + s[i];
    }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
