/*
AUTHOR: $%U%$
CREATED: $%D%$.$%M%$.$%Y%$ $%h%$:$%m%$:$%s%$
LANG: C++14
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

// data
const int maxn = 1e3 + 10;
int n, m;
string g[maxn];
vi adj[maxn * maxn];
char c[maxn * maxn];
int vist[maxn * maxn];

int tn(int i, int j) { return i * m + j; }

void dfs(int u, int p, char d = '.') {
  vist[u] = p;
  if (c[u] == '.') c[u] = d;
  for (auto v : adj[u]) {
    if (vist[v] ^ p) {
      dfs(v, p, c[u]);
      if (c[u] == '.') c[u] = c[v];
    }
  }
}

void solve() {
  cin >> n >> m;
  REP(i, 0, n) {
    cin >> g[i];
    REP(j, 0, m) c[tn(i, j)] = g[i][j];
    int s = 0;
    REP(j, 0, m) {
      if (g[i][j] == '#') {
        for (int k = 0; s + k < j - 1 - k; ++k) {
          int a = tn(i, s + k), b = tn(i, j - 1 - k);
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
        s = j + 1;
      }
    }
    for (int k = 0; s + k < m - 1 - k; ++k) {
      int a = tn(i, s + k), b = tn(i, m - 1 - k);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  REP(j, 0, m) {
    int s = 0;
    REP(i, 0, n) {
      if (g[i][j] == '#') {
        for (int k = 0; s + k < i - 1 - k; k++) {
          int a = tn(s + k, j), b = tn(i - 1 - k, j);
          adj[a].push_back(b);
          adj[b].push_back(a);
        }
        s = i + 1;
      }
    }
    for (int k = 0; s + k < n - 1 - k; k++) {
      int a = tn(s + k, j), b = tn(n - 1 - k, j);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
  }
  REP(i, 0, n) {
    REP(j, 0, m) {
      if (g[i][j] == '#' || vist[tn(i, j)]) continue;
      dfs(tn(i, j), 1);
      dfs(tn(i, j), 2);
    }
  }

  int ans = 0;
  REP(i, 0, n) REP(j, 0, m) if (g[i][j] == '.' && c[tn(i, j)] != '.')++ ans;
  cout << ans << '\n';
  REP(i, 0, n) {
    REP(j, 0, m) cout << c[tn(i, j)];
    cout << '\n';
  }
  REP(i, 0, n * m) adj[i].clear(), vist[i] = 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t, kase = 0;
  cin >> t;
  while (t--) {
    cout << "Case #" << ++kase << ": ";
    solve();
  }
  return 0;
}
