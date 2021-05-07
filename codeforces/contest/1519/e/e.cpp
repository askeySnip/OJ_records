/*
AUTHOR: lz.askey
CREATED: 05.05.2021 19:15:22
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
struct point {
  int a, b, c, d;
};
typedef pair<ll, ll> frac;
typedef pair<int, int> pt;

// data
int n;
vector<point> a;
map<frac, int> sv;
vector<vector<pt>> g;
vi used;
vector<pt> ans;

ll gcd(ll x, ll y) { return !y ? x : gcd(y, x % y); }

frac norm(ll x, ll y) {
  ll g = gcd(x, y);
  return {x / g, y / g};
}

int dfs(int v) {
  used[v] = 1;
  int cur = -1;
  for (auto it : g[v]) {
    int u = it.ff;
    int i = it.ss;
    if (used[u] == 1) continue;
    int nw = i;
    if (!used[u]) {
      int tmp = dfs(u);
      if (tmp != -1) {
        ans.push_back({nw, tmp});
        nw = -1;
      }
    }
    if (nw != -1) {
      if (cur != -1) {
        ans.push_back({cur, nw});
        cur = -1;
      } else
        cur = nw;
    }
  }
  used[v] = 2;
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  a.resize(n);
  REP(i, 0, n) cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
  g.resize(2 * n + 10);
  REP(i, 0, n) {
    frac f1 = norm((a[i].a + a[i].b) * 1ll * a[i].d, 1ll * a[i].b * a[i].c);
    frac f2 = norm(a[i].a * 1ll * a[i].d, (a[i].c + a[i].d) * 1ll * a[i].b);
    if (!sv.count(f1)) {
      int k = sv.size();
      sv[f1] = k;
    }
    if (!sv.count(f2)) {
      int k = sv.size();
      sv[f2] = k;
    }
    g[sv[f1]].push_back({sv[f2], i});
    g[sv[f2]].push_back({sv[f1], i});
  }
  used.resize(sv.size());
  REP(i, 0, sz(sv)) if (!used[i]) dfs(i);
  cout << ans.size() << "\n";
  for (auto it : ans) cout << it.ff + 1 << " " << it.ss + 1 << "\n";
  return 0;
}
