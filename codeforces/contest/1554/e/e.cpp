/*
AUTHOR: lz.askey
CREATED: 30.07.2021 14:46:20
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
const int mod = 998244353;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
const int N = 1e5 + 10;
vi g[N];
int dp[N];
int ok, d;

void dfs(int u, int p = 0) {
  if (!ok) return;
  for (auto v : g[u]) {
    if (v ^ p) {
      dfs(v, u);
    }
  }
  if (dp[u] % d != 0) {
    if (p) dp[u]++;
    if (dp[u] % d != 0) {
      ok = 0;
      return;
    }
  } else
    dp[p]++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    REP(i, 1, n) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vi ans(n + 1, 0);
    ans[1] = 1;
    REP(i, 1, n) ans[1] = (ans[1] + ans[1]) % mod;
    for (d = 2; d <= n; d++) {
      if ((n - 1) % d) continue;
      ok = 1;
      dfs(1);
      ans[d] = ok;
      fill(dp, dp + n + 1, 0);
    }
    for (int i = n; i > 0; i--) {
      for (int j = i + i; j <= n; j += i) {
        ans[i] = (ans[i] - ans[j] + mod) % mod;
      }
    }
    REP(i, 1, n + 1) {
      if (i > 1) cout << " ";
      cout << ans[i];
    }
    cout << '\n';
    REP(i, 0, n + 1) g[i].clear();
  }
  return 0;
}
