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
#define bit(x, i) (x & (1 << i))
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr << #vari << " = " << (vari) << endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size() - 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
int n;
vi e[100010];
int sz[100010];
int m;
vi p;
vector<ll> path;

void dfs(int u, int p) {
  sz[u] = 1;
  for (auto v : e[u]) {
    if (v == p) continue;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

void dfs1(int u, int p) {
  for (auto v : e[u]) {
    if (v == p) continue;
    // cout << "dfs" << u << " " << v << endl;
    path.push_back(1LL * sz[v] * (sz[1] - sz[v]));
    dfs1(v, u);
  }
}

void solve() {
  path.clear();
  dfs(1, -1);
  dfs1(1, -1);
  sort(path.begin(), path.end());
  if (m < n - 1) {
    REP(i, m, n - 1) p.push_back(1);
  }
  sort(p.begin(), p.end());
  ll ans = 0, mx = 0;
  REP(i, 0, n - 1) {
    mx = max(path[i] * p[i], mx);
    ans += path[i] * p[i];
    ans %= mod;
  }
  ll t = 1;
  REP(i, n - 1, m) t *= p[i], t %= mod;
  ans += (((t - 1) % mod) * (mx % mod)) % mod;
  ans %= mod;
  printf("%lld\n", ans);
}

int main() {
  int t;
  getI(t);
  while (t--) {
    getI(n);
    REP(i, 1, n + 1) e[i].clear();
    int u, v;
    REP(i, 1, n) {
      getII(u, v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    getI(m);
    p.resize(m);
    REP(i, 0, m) getI(p[i]);
    solve();
  }
  return 0;
}
