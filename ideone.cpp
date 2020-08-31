/*...Part - 01...*/

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
//#include <bits/stdc++.h>
using namespace std;

/*...Part - 02...*/

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;

int Int() {
  int x;
  scanf("%d", &x);
  return x;
}
ll Long() {
  ll x;
  scanf("%lld", &x);
  return x;
}

/*...Part - 03...*/
/*....Debugger....*/

#define error(args...)                       \
  {                                          \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
  }
void err(istream_iterator<string> it) { cout << endl; }
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << ' ';
  err(++it, args...);
}

/*...Part - 04...*/
/*...Needed to change according to problem requirements...*/

const int N = (int)5e4 + 5;
const int maxN = (int)1e6 + 6;
const ll Mod = (ll)1e9 + 7;
const int inf = (int)2e9;
const ll Inf = (ll)1e18;

/*..........................................................*/
/*...Part - 05...*/

#define debug(x) cerr << #x << " = " << x << '\n';
#define rep(i, b, e)                                        \
  for (__typeof(e) i = (b); i != (e + 1) - 2 * ((b) > (e)); \
       i += 1 - 2 * ((b) > (e)))
#define Int Int()
#define Long Long()
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define mem(a) memset(a, 0, sizeof a)
#define memn(a) memset(a, -1, sizeof a)

/*...Part - 06...*/
/*...... ! Code start from here ! ......*/

vvi g;
int chainHead[N], chainID[N], cost[N], pos[N], chainNo, cur;
int a[N], par[N][17], dep[N], subsz[N], tree[N << 2], n;

void dfs(int s, int p = -1) {
  dep[s] = 1 + dep[p];
  par[s][0] = p;
  subsz[s] = 1;
  for (int i = 1; i < 16; ++i) par[s][i] = par[par[s][i - 1]][i - 1];
  for (int i : g[s]) {
    if (i != p) {
      dfs(i, s);
      subsz[s] += subsz[i];
    }
  }
}

void HLD(int s, int p = -1) {
  if (chainHead[chainNo] == -1) {
    chainHead[chainNo] = s;
  }
  chainID[s] = chainNo;
  pos[s] = ++cur;
  a[cur] = cost[s];
  int id = -1, mx = -1;
  for (int i : g[s]) {
    if (i == p) continue;
    if (subsz[i] > mx) {
      mx = subsz[i];
      id = i;
    }
  }
  if (id != -1) HLD(id, s);
  for (int i : g[s]) {
    if (i == p or i == id) continue;
    ++chainNo;
    HLD(i, s);
  }
}

void fresh() {
  memn(chainHead);
  g.clear();
  mem(tree);
  mem(par);
  chainNo = 0;
  cur = 0;
}

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

void build(int i, int b, int e) {
  if (b == e) {
    tree[i] = a[b];
    return;
  }

  int mid = (b + e) >> 1;
  build(i << 1, b, mid);
  build(i << 1 | 1, mid + 1, e);
  tree[i] = gcd(tree[i << 1], tree[i << 1 | 1]);
}

void update(int i, int b, int e, int p, int v) {
  if (p > e or p < b) return;
  if (p == b and p == e) {
    tree[i] = v;
    return;
  }
  int mid = (b + e) >> 1;
  update(i << 1, b, mid, p, v);
  update(i << 1 | 1, mid + 1, e, p, v);
  tree[i] = gcd(tree[i << 1], tree[i << 1 | 1]);
}

int query(int i, int b, int e, int l, int r) {
  if (b > r or e < l) return 0;
  if (l <= b and e <= r) return tree[i];
  int mid = (b + e) >> 1;
  return gcd(query(i << 1, b, mid, l, r), query(i << 1 | 1, mid + 1, e, l, r));
}

int getLca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  int d = dep[a] - dep[b];
  for (int i = 15; i >= 0; --i)
    if (d & (1 << i)) a = par[a][i];
  if (a == b) return a;
  for (int i = 15; i >= 0; --i) {
    if (par[a][i] != par[b][i]) a = par[a][i], b = par[b][i];
  }
  return par[a][0];
}

int chain_query(int u, int v) {
  if (u == v) return cost[u];
  int uchain, vchain = chainID[v], res = 0;
  while (1) {
    uchain = chainID[u];
    if (uchain == vchain) {
      res = gcd(res, query(1, 1, n, pos[v], pos[u]));
      break;
    }
    res = gcd(res, query(1, 1, n, pos[chainHead[uchain]], pos[u]));
    u = chainHead[uchain];
    u = par[u][0];
  }
  return res;
}

int getResult(int a, int b) {
  int x = getLca(a, b);
  int u = chain_query(a, x);
  int v = chain_query(b, x);
  return gcd(u, v);
}

int main() {
  // freopen("input.txt","r",stdin) ;
  // freopen("output.txt","w",stdout) ;
  while (scanf("%d", &n) == 1) {
    assert(n <= 50000);
    fresh();
    g.resize(n);
    for (int i = 0; i < n; ++i) cost[i] = Int;
    int x, y;
    for (int i = 1; i < n; ++i) {
      scanf("%d %d", &x, &y);
      g[x].pb(y);
      g[y].pb(x);
      assert(x >= 0 and x <= n - 1);
      assert(y >= 0 and y <= n - 1);
    }
    dfs(0);
    HLD(0);
    build(1, 1, n);
    int q = Int, tp;
    while (q--) {
      scanf("%d %d %d", &tp, &x, &y);
      assert(x >= 0 and x <= n - 1);
      assert(y >= 0 and y <= n - 1);
      if (tp == 1) {
        printf("%d\n", getResult(x, y));
      } else {
        update(1, 1, n, pos[x], y);
        cost[x] = y;
      }
    }
  }
  return 0;
}

/*...Always look at the part - 04...*/
/*...............END................*/
