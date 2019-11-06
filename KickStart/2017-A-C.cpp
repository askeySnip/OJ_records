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
const ll inf = 1e17;
const int mod = 1e9 + 7;

int n;
int x[2010], y[2010], z[2010], r[2010];

bool inside(ll xd1, ll yd1, ll zd1, ll xu1, ll yu1, ll zu1, ll xd2, ll yd2,
            ll zd2, ll xu2, ll yu2, ll zu2) {
  REP(i, 0, n) {
    int cnt = 0;
    if (x[i] - r[i] < xd1 || x[i] + r[i] > xu1 || y[i] - r[i] < yd1 ||
        y[i] + r[i] > yu1 || z[i] - r[i] < zd1 || z[i] + r[i] > zu1)
      cnt++;
    if (x[i] - r[i] < xd2 || x[i] + r[i] > xu2 || y[i] - r[i] < yd2 ||
        y[i] + r[i] > yu2 || z[i] - r[i] < zd2 || z[i] + r[i] > zu2)
      cnt++;
    if (cnt == 2) return false;
  }
  return true;
}

bool check(ll len) {
  ll xmin = inf, xmax = -inf, ymin = inf, ymax = -inf;
  ll zmin = inf, zmax = -inf;
  REP(i, 0, n) {
    xmin = min(xmin, 1LL * x[i] - r[i]);
    xmax = max(xmax, 1LL * x[i] + r[i]);
    ymin = min(ymin, 1LL * y[i] - r[i]);
    ymax = max(ymax, 1LL * y[i] + r[i]);
    zmin = min(zmin, 1LL * z[i] - r[i]);
    zmax = max(zmax, 1LL * z[i] + r[i]);
  }
  ll xd[4] = {xmin, xmin + len, xmax - len, xmax};
  ll yd[4] = {ymin, ymin + len, ymax - len, ymax};
  ll zd[4] = {zmin, zmin + len, zmax - len, zmax};

  for (int x1 = 0; x1 < 4; x1 += 2) {
    for (int y1 = 0; y1 < 4; y1 += 2) {
      for (int z1 = 0; z1 < 4; z1 += 2) {
        for (int x2 = 0; x2 < 4; x2 += 2) {
          for (int y2 = 0; y2 < 4; y2 += 2) {
            for (int z2 = 0; z2 < 4; z2 += 2) {
              if (inside(xd[x1], yd[y1], zd[z1], xd[x1 + 1], yd[y1 + 1],
                         zd[z1 + 1], xd[x2], yd[y2], zd[z2], xd[x2 + 1],
                         yd[y2 + 1], zd[z2 + 1])) {
                return true;
              }
            }
          }
        }
      }
    }
  }
  return false;
}

ll solve() {
  ll l = 0, h = inf, mid;
  while (l < h) {
    mid = (l + h) / 2;
    if (check(mid))
      h = mid;
    else {
      l = mid + 1;
    }
  }
  return l;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d%d%d%d", &x[i], &y[i], &z[i], &r[i]);
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }
  return 0;
}
