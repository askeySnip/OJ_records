/*
AUTHOR: lz.askey
CREATED: 31.07.2021 20:03:32
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
typedef vector<pair<int, int>> vii;
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
class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return i == p[i] ? i : (p[i] = findSet(p[i])); }
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
int n, q;
vector<tuple<int, int, int>> e;
vector<vii> g;
int l = 19;
vector<vi> up;
vector<int> tin, tout;
int T = 0;
vector<int> xr;
vi ft;

void dfs(int v, int p, int cur) {
  tin[v] = T++;
  xr[v] = cur;
  up[v][0] = p;
  REP(i, 1, l) { up[v][i] = up[up[v][i - 1]][i - 1]; }
  for (auto& val : g[v]) {
    if (val.first == p) continue;
    dfs(val.first, v, cur ^ val.second);
  }
  tout[v] = T;
}

void buildLCA() {
  up.assign(n, vi(l, -1));
  tin.assign(n, -1);
  tout.assign(n, -1);
  xr.assign(n, 0);
  T = 0;
  REP(i, 0, n) {
    if (tin[i] == -1) dfs(i, i, 0);
  }
}

bool isPar(int p, int v) { return tin[p] <= tin[v] && tout[p] >= tout[v]; }

int lca(int u, int v) {
  if (isPar(u, v)) return u;
  if (isPar(v, u)) return v;

  for (int i = l - 1; i >= 0; i--) {
    if (!isPar(up[v][i], u)) {
      v = up[v][i];
    }
  }
  return up[v][0];
}

int sum(int p) {
  ++p;
  int s = 0;
  for (; p; p -= p & (-p)) {
    s += ft[p];
  }
  return s;
}

void inc(int p, int val) {
  for (p = p + 1; p < ft.size(); p += p & (-p)) {
    ft[p] += val;
  }
}

void addOnPath(int v, int ca) {
  while (v != ca) {
    inc(tin[v], 1);
    inc(tout[v], -1);
    v = up[v][0];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> q;
  e.resize(q);
  ft.assign(2 * n + 5, 0);

  REP(i, 0, q) {
    int u, v, x;
    cin >> u >> v >> x;
    --u, --v;
    e[i] = make_tuple(u, v, x);
  }
  g.resize(n);
  UnionFind uf(n);
  vi ans(q, -1);

  REP(i, 0, q) {
    int u, v, x;
    tie(u, v, x) = e[i];
    if (!uf.isSameSet(u, v)) {
      uf.unionSet(u, v);
      ans[i] = 1;
      g[u].emplace_back(v, x);
      g[v].emplace_back(u, x);
    }
  }

  buildLCA();

  REP(i, 0, q) {
    if (ans[i] != -1) continue;
    int u, v, x;
    tie(u, v, x) = e[i];
    int xp = xr[u] ^ xr[v];
    if ((xp ^ x) != 1) continue;
    int ca = lca(u, v);

    int val = sum(tin[u]) + sum(tin[v]) - 2 * sum(tin[ca]);
    // error(i, val);
    if (val > 0) continue;
    ans[i] = 1;
    // error(i, ans[i]);
    addOnPath(u, ca);
    addOnPath(v, ca);
  }
  for (auto f : ans) {
    cout << (f == 1 ? "YES\n" : "NO\n");
  }
  return 0;
}
