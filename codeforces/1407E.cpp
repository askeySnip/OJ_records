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
const int maxn = 1e6 + 10;
int n, m;
vi bg[maxn], rg[maxn];
int b[maxn], r[maxn], d[maxn], col[maxn];

int main() {
  gii(n, m);
  REP(i, 0, m) {
    int u, v, t;
    giii(u, v, t);
    --u, --v;
    if (!t)
      bg[v].push_back(u);
    else
      rg[v].push_back(u);
  }
  REP(i, 0, n) b[i] = r[i] = d[i] = n;
  queue<int> q;
  q.push(n - 1);
  b[n - 1] = r[n - 1] = d[n - 1] = 0;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (auto to : bg[x]) {
      if (b[to] < n) continue;
      b[to] = d[x] + 1;
      if (max(b[to], r[to]) < n) {
        q.push(to);
        d[to] = max(b[to], r[to]);
      }
    }
    for (auto to : rg[x]) {
      if (r[to] < n) continue;
      r[to] = d[x] + 1;
      if (max(b[to], r[to]) < n) {
        q.push(to);
        d[to] = max(b[to], r[to]);
      }
    }
  }
  if (d[0] == n)
    printf("-1\n");
  else
    printf("%d\n", d[0]);

  REP(i, 0, n) {
    if (b[i] > r[i])
      col[i] = 0;
    else
      col[i] = 1;
  }
  REP(i, 0, n) { printf("%d", col[i]); }
  printf("\n");
  return 0;
}
