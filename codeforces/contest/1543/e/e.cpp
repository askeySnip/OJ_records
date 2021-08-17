/*
AUTHOR: lz.askey
CREATED: 24.07.2021 17:43:48
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

// data
int n, m;
vi p;
vector<set<int>> s;
vector<vi> adj;

void permuteHypercube() {
  REP(i, 0, m) p[i] = -1;
  vi used(m, 0);
  p[0] = 0;
  used[0] = true;
  REP(u, 1, m) {
    vi req;
    REP(i, 0, n) {
      int v = u ^ (1 << i);
      if (v < u) req.push_back(v);
    }
    if (req.size() == 1) {
      int v = req[0];
      REP(i, 0, adj[p[v]].size()) {
        int w = adj[p[v]][i];
        if (used[w]) continue;
        p[u] = w;
        used[w] = true;
        break;
      }
    } else {
      int v = req[0];
      REP(i, 0, adj[p[v]].size()) {
        int w = adj[p[v]][i];
        if (used[w]) continue;
        if (s[w].count(p[req[1]])) {
          p[u] = w;
          used[w] = true;
          break;
        }
      }
    }
  }
}
void clear() {
  p.clear();
  s.clear();
  adj.clear();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    clear();
    cin >> n;
    m = (1 << n);
    p.resize(m);
    s.resize(m);
    adj.resize(m);
    REP(i, 0, n * m / 2) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      s[u].insert(v);
      s[v].insert(u);
    }
    permuteHypercube();
    REP(i, 0, m) cout << p[i] << " ";
    cout << "\n";
    if (n != 1 && n != 2 && n != 4 && n != 8 && n != 16) {
      cout << -1 << "\n";
      continue;
    }
    vi temp(m);
    REP(i, 0, m) {
      int clr = 0;
      REP(j, 0, n) {
        if (i & (1 << j)) {
          clr ^= j;
        }
      }
      temp[i] = clr;
    }
    vi c(m);
    REP(i, 0, m) c[p[i]] = temp[i];
    REP(i, 0, m) cout << c[i] << " ";
    cout << "\n";
  }
  return 0;
}
