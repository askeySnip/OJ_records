/*
AUTHOR: lz.askey
CREATED: 04.08.2021 23:26:59
LANG: C++11
*/
#include <assert.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <iterator>
#include <map>
#include <new>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define bit(x, i) (x & (1 << i))
#define in(i, l, r) (l < i && i < r)
#define linr(i, l, r) (l <= i && i <= r)
#define lin(i, l, r) (l <= i && i < r)
#define inr(i, l, r) (l < i && i <= r)
#define gi(a) scanf("%d", &a)
#define gii(a, b) scanf("%d%d", &a, &b)
#define giii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define gs(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define c2i(c) (c - '0')
#define sz(x) ((int)((x).size()))
#define all(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
// for debug
#define what_is(x) \
  cerr << "Line " << __LINE__ << ": " << #x << " is " << (x) << endl;
#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(istream_iterator<string> it) { cerr << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << endl;
  err(++it, args...);
}

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
vector<vi> g;
int f[210][210];
vi dep;
int fa[210][10];

int fast_pow(int b, int e) {
  int r = 1;
  while (e) {
    if (e & 1) r = (1ll * r * b) % mod;
    b = 1ll * b * b % mod;
    e >>= 1;
  }
  return r;
}

void dfs(int u, int p) {
  dep[u] = dep[p] + 1;
  fa[u][0] = p;
  REP(i, 1, 10) { fa[u][i] = fa[fa[u][i - 1]][i - 1]; }
  for (auto v : g[u]) {
    if (v == p) continue;
    dfs(v, u);
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) swap(u, v);
  for (int i = 9; i >= 0; i--) {
    if (dep[fa[u][i]] >= dep[v]) u = fa[u][i];
  }
  if (u == v) return u;
  for (int i = 9; i >= 0; i--) {
    if (fa[u][i] != fa[v][i]) u = fa[u][i], v = fa[v][i];
  }
  return fa[u][0];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  g.resize(n + 1);
  dep.assign(n + 1, 0);
  int inv2 = fast_pow(2, mod - 2);
  REP(i, 1, n + 1) f[0][i] = 1, f[i][0] = 0;
  REP(i, 1, n + 1) {
    REP(j, 1, n) { f[i][j] = 1ll * (f[i - 1][j] + f[i][j - 1]) * inv2 % mod; }
  }
  REP(i, 1, n + 1) {
    int x, y;
    cin >> x >> y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  int ans = 0;
  int invn = fast_pow(n, mod - 2);
  REP(p, 1, n + 1) {
    dfs(p, 0);
    int s = 0;
    REP(i, 1, n + 1) {
      REP(j, 1, i) {
        int d = lca(i, j);
        if (d == i)
          s = (s + 1) % mod;
        else if (d == j)
          continue;
        else
          s = (s + f[dep[i] - dep[d]][dep[j] - dep[d]]) % mod;
      }
    }
    ans = (ans + 1ll * s * invn) % mod;
  }
  cout << ans << '\n';
  return 0;
}
