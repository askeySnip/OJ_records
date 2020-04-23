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
int n, k;
vi e[200010];
int dep[200010];
int sz[200010];
int det[200010];

bool cmp(int a, int b) { return a > b; }

int dfs(int u, int p) {
  dep[u] = dep[p] + 1;
  sz[u] = 1;
  for (auto v : e[u]) {
    if (v == p) continue;
    sz[u] += dfs(v, u);
  }
  det[u] = sz[u] - dep[u];
  return sz[u];
}

void solve() {
  dfs(1, 0);
  nth_element(det + 1, det + n - k, det + 1 + n, cmp);
  ll ans = 0;
  REP(i, 1, n - k + 1) ans += det[i];
  printf("%lld\n", ans);
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    int u, v;
    REP(i, 0, n - 1) {
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    solve();
  }
  return 0;
}
