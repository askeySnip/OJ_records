/*
ID: leezhen
TASK: practice
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
int n;
vi adj[100010];
int sz[100010];
int par[100010];
int dep[100010];

void dfs(int u, int p) {
  sz[u] = 1;
  for (int v : adj[u]) {
    if (v == p) continue;
    par[v] = u;
    dep[v] = dep[u] + 1;
    dfs(v, u);
    sz[u] += sz[v];
  }
}

int main() {
  int t;
  gi(t);
  while (t--) {
    gi(n);
    int x, y;
    REP(i, 1, n + 1) adj[i].clear();
    REP(i, 0, n - 1) {
      gii(x, y);
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    par[1] = 0;
    dep[1] = 0;
    dfs(1, 0);
    int val = inf;
    vi cen;
    REP(i, 1, n + 1) {
      if (par[i]) {
        int p = par[i];
        int cur = sz[1] - sz[i];
        for (auto v : adj[i]) {
          if (v == p) continue;
          cur = max(cur, sz[v]);
        }
        if (cur < val) {
          val = cur;
          cen.clear();
          cen.push_back(i);
        } else if (cur == val)
          cen.push_back(i);
      } else {
        int cur = 0;
        for (auto v : adj[i]) {
          cur = max(cur, sz[v]);
        }
        if (cur < val) {
          val = cur;
          cen.clear();
          cen.push_back(i);
        } else if (cur == val)
          cen.push_back(i);
      }
    }
    if (cen.size() == 1) {
      printf("2 %d\n", par[2]);
      printf("2 %d\n", par[2]);
    } else {
      if (dep[cen[0]] > dep[cen[1]]) {
        swap(cen[0], cen[1]);
      }
      int cut = cen[1];
      while (true) {
        bool f = true;
        for (int v : adj[cut]) {
          if (v == par[cut])
            continue;
          else {
            cut = v;
            f = false;
            break;
          }
        }
        if (f) break;
      }
      printf("%d %d\n", par[cut], cut);
      printf("%d %d\n", cut, cen[0]);
    }
  }
  return 0;
}
