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
#define gi(a) scanf("%lld", &a)
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
const int N = 200010;
ll n;
ll a[N], b[N];
int vist[N];
vi path;

void dfs(int u) {
  vist[u] = 1;
  if (b[u] != -1 && !vist[b[u]]) dfs(b[u]);
  path.push_back(u);
}

int main() {
  gi(n);
  REP(i, 1, n + 1) gi(a[i]);
  REP(i, 1, n + 1) gi(b[i]);
  REP(i, 1, n + 1) {
    if (!vist[i]) dfs(i);
  }
  ll ans = 0;
  reverse(all(path));
  vi use(n + 1, 1);
  vi useless;
  REP(i, 0, n) {
    int u = path[i];
    if (a[u] < 0) {
      use[i] = 0;
      useless.push_back(u);
      continue;
    }
    ans += a[u];
    a[b[u]] += a[u];
  }
  reverse(all(useless));
  REP(i, 0, useless.size()) {
    int u = useless[i];
    ans += a[u];
    a[b[u]] += a[u];
  }
  printf("%lld\n", ans);
  REP(i, 0, n) {
    if (use[i]) printf("%d ", path[i]);
  }
  REP(i, 0, useless.size()) { printf("%d ", useless[i]); }
  printf("\n");
  return 0;
}
