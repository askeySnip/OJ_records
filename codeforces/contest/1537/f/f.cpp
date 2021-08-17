/*
AUTHOR: lz.askey
CREATED: 08.08.2021 11:10:15
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
int n, m;
vi v, t;
vector<vi> e;
vi color;

bool dfs(int u, int p) {
  color[u] = 3 - color[p];
  for (auto v : e[u]) {
    if (v == p) continue;
    if (!color[v]) {
      if (dfs(v, u)) return true;
    } else if (color[v] == color[u])
      return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int kase;
  cin >> kase;
  while (kase--) {
    cin >> n >> m;
    v.resize(n + 1), t.resize(n + 1);
    color.assign(n + 1, 0);
    color[0] = 2;
    REP(i, 1, n + 1) cin >> v[i];
    REP(i, 1, n + 1) cin >> t[i];
    e.resize(n + 1);
    REP(i, 0, m) {
      int u, v;
      cin >> u >> v;
      e[u].push_back(v);
      e[v].push_back(u);
    }
    ll sv = 0, st = 0;
    REP(i, 1, n + 1) sv += v[i];
    REP(i, 1, n + 1) st += t[i];
    if (abs(sv - st) & 1) {
      cout << "NO\n";
      continue;
    }
    if (dfs(1, 0)) {
      cout << "YES\n";
      continue;
    }
    sv = 0, st = 0;
    REP(i, 1, n + 1) {
      if (color[i] == 1) sv += t[i] - v[i];
      if (color[i] == 2) st += t[i] - v[i];
    }
    if (sv == st)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
