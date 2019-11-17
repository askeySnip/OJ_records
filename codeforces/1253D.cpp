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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
class UnionFind {
 private:
  vi rank, p;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

// data
int n, m;
vi e[200010];
int vist[200010];

int maxn;

void dfs(int u) {
  vist[u] = 1;
  REP(i, 0, e[u].size()) {
    if (!vist[e[u][i]]) {
      maxn = max(maxn, e[u][i]);
      dfs(e[u][i]);
    }
  }
}

void solve() {
  vii lr;
  REP(i, 0, n) {
    if (!vist[i]) {
      maxn = -1;
      dfs(i);
      lr.pb(ii(i, maxn));
    }
  }
  vii flr;
  sort(lr.begin(), lr.end());
  int l = lr[0].first, r = lr[0].second;
  REP(i, 0, lr.size()) {
    if (lr[i].first <= r)
      r = max(r, lr[i].second);
    else {
      flr.push_back(ii(l, r));
      l = lr[i].first;
      r = lr[i].second;
    }
  }
  flr.push_back(ii(l, r));
  UnionFind uf(n + 1);
  REP(i, 0, n) {
    REP(j, 0, e[i].size()) { uf.unionSet(i, e[i][j]); }
  }
  int ans = 0;
  REP(i, 0, flr.size()) {
    l = flr[i].first, r = flr[i].second;
    REP(j, l, r + 1) {
      if (!uf.isSameSet(l, j)) {
        ans++;
        uf.unionSet(l, j);
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d%d", &n, &m);
    int u, v;
    REP(i, 0, m) {
      scanf("%d%d", &u, &v);
      u--;
      v--;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    solve();
  }
  return 0;
}