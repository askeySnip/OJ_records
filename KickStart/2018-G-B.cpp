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

int n, q;
int x[400010], y[400010], z[400010];
int l[400010], r[400010];
ii query[400010];
int ls[900010];
int gin[900010], gout[900010];
int lsc;
int ans[400010];

ll solve() {
  memset(gin, 0, sizeof gin);
  memset(gout, 0, sizeof gout);
  memset(ans, 0, sizeof ans);
  set<int> s;
  REP(i, 1, n + 1) {
    l[i] = min(x[i], y[i]) + 1;
    r[i] = max(x[i], y[i]) + 1;
    s.insert(l[i]);
    s.insert(r[i]);
  }
  REP(i, 1, q + 1) query[i].first = z[i] + 1, query[i].second = i;
  lsc = 0;
  for (auto it = s.begin(); it != s.end(); it++) {
    ls[++lsc] = *it;
  }
  REP(i, 1, n + 1) {
    l[i] = lower_bound(ls + 1, ls + lsc + 1, l[i]) - ls;
    r[i] = lower_bound(ls + 1, ls + lsc + 1, r[i]) - ls;
    gin[r[i]]++;
    gout[l[i]]++;
  }
  sort(query + 1, query + q + 1);
  ls[0] = 0, ls[lsc + 1] = 0;
  int label = 1, cnt = 0;
  ll sum = 0;
  for (int i = lsc; i >= 1; i--) {
    ll nxt = sum + 1LL * (ls[i + 1] - ls[i]) * cnt;
    while (label <= q && query[label].first <= nxt) {
      int tmp = query[label].first - sum;
      int res = ls[i + 1] - (tmp + cnt - 1) / cnt;
      ans[query[label].second] = res;
      label++;
    }
    nxt += gin[i];
    while (label <= q && query[label].first <= nxt) {
      ans[query[label].second] = ls[i];
      label++;
    }
    cnt -= gout[i];
    cnt += gin[i];
    sum = nxt;
  }
  ll ret = 0;
  REP(i, 1, q + 1) { ret += 1LL * ans[i] * i; }
  return ret;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int x1, x2, a, b, c, m;
  while (t--) {
    scanf("%d%d", &n, &q);
    scanf("%d%d%d%d%d%d", &x1, &x2, &a, &b, &c, &m);
    x[1] = x1, x[2] = x2;
    REP(i, 3, n + 1) x[i] = (1LL * a * x[i - 1] + 1LL * b * x[i - 2] + c) % m;
    scanf("%d%d%d%d%d%d", &x1, &x2, &a, &b, &c, &m);
    y[1] = x1, y[2] = x2;
    REP(i, 3, n + 1) y[i] = (1LL * a * y[i - 1] + 1LL * b * y[i - 2] + c) % m;
    scanf("%d%d%d%d%d%d", &x1, &x2, &a, &b, &c, &m);
    z[1] = x1, z[2] = x2;
    REP(i, 3, q + 1) z[i] = (1LL * a * z[i - 1] + 1LL * b * z[i - 2] + c) % m;
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }
  return 0;
}
