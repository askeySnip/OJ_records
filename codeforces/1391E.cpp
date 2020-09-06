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
const int N = 500010;
int n, m;
vi adj[N];
vi all[N];
int dep[N];
int par[N];
bool vist[N];
bool flag;
int pairs;

void dfs(int u) {
  if (flag) return;
  vist[u] = 1;
  pairs -= all[dep[u]].size() / 2;
  all[dep[u]].pb(u);
  pairs += all[dep[u]].size() / 2;
  if (dep[u] >= (n + 1) / 2) {
    flag = true;
    printf("PATH\n");
    printf("%d\n", dep[u]);
    int cur = u;
    while (cur) {
      printf("%d ", cur);
      cur = par[cur];
    }
    printf("\n");
    return;
  }
  for (auto v : adj[u]) {
    if (vist[v]) continue;
    dep[v] = dep[u] + 1;
    par[v] = u;
    dfs(v);
  }
}

int main() {
  int t;
  gi(t);
  while (t--) {
    gii(n, m);
    int u, v;
    REP(i, 1, n + 1) {
      adj[i].clear();
      all[i].clear();
      dep[i] = 0;
      vist[i] = 0;
    }
    flag = false;
    pairs = 0;
    REP(i, 0, m) {
      gii(u, v);
      adj[u].pb(v);
      adj[v].pb(u);
    }
    dep[1] = 1;
    dfs(1);
    if (!flag) {
      printf("PAIRING\n");
      printf("%d\n", pairs);
      for (int i = 1; i < (n + 1) / 2; i++) {
        for (int j = 0; j + 1 < all[i].size(); j += 2) {
          printf("%d %d\n", all[i][j], all[i][j + 1]);
        }
      }
    }
  }
  return 0;
}
