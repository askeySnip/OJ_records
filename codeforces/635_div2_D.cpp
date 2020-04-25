/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
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
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int nr, ng, nb;
ll ans;

ll dis(ll a, ll b, ll c) {
  return (a - b) * (a - b) + (a - c) * (a - c) + (b - c) * (b - c);
}

void f(vi& a, vi& b, vi& c) {
  for (auto x : a) {
    auto y = lower_bound(b.begin(), b.end(), x);
    auto z = upper_bound(c.begin(), c.end(), x);
    if (z == c.begin() || y == b.end()) continue;
    z--;
    ans = min(ans, dis(*y, *z, x));
  }
}

void solve() {
  vi r(nr), g(ng), b(nb);
  REP(i, 0, nr) scanf("%d", &r[i]);
  REP(i, 0, ng) scanf("%d", &g[i]);
  REP(i, 0, nb) scanf("%d", &b[i]);
  sort(r.begin(), r.end());
  sort(g.begin(), g.end());
  sort(b.begin(), b.end());
  ans = 9e18;
  f(r, g, b);
  f(r, b, g);
  f(g, r, b);
  f(g, b, r);
  f(b, r, g);
  f(b, g, r);
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &nr, &ng, &nb);
    solve();
  }
  return 0;
}
