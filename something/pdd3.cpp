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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct
class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return i == p[i] ? i : p[i] = findSet(p[i]); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y])
        p[y] = x;
      else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

// data
int n, m, t;
vii z, w;

int main() {
  scanf("%d%d%d", &n, &m, &t);
  int x, y;
  int ans = inf;
  REP(i, 0, n) {
    scanf("%d%d", &x, &y);
    z.emplace_back(y, x);
    if (y >= t) ans = min(ans, x);
  }
  REP(i, 0, m) {
    scanf("%d%d", &x, &y);
    w.emplace_back(y, x);
    if (y >= t) ans = min(ans, x);
  }
  if (t == 0) {
    printf("0\n");
    return 0;
  }
  sort(z.begin(), z.end());
  vi f(z.size(), inf);
  f[z.size() - 1] = z.back().second;
  for (int i = z.size() - 2; i >= 0; i--) {
    f[i] = min(z[i].second, f[i + 1]);
  }
  vi zz(z.size());
  REP(i, 0, z.size()) zz[i] = z[i].first;
  REP(i, 0, w.size()) {
    if (w[i].first >= t) continue;
    int tt = t - w[i].first;
    auto it = lower_bound(zz.begin(), zz.end(), tt) - zz.begin();
    if (it >= zz.size()) continue;
    ans = min(ans, w[i].second + f[it]);
  }
  if (ans == inf)
    printf("-1\n");
  else
    printf("%d\n", ans);
  return 0;
}
