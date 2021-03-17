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
vector<vi> dir = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                  {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

// struct

// data
int n, m, l;
vi mat;
int d[20][30000];
vi b;
map<int, int> idx;

void sp(int s) {
  d[idx[s]][s] = 0;
  queue<int> q;
  q.push(s);
  vi vist(n * m * l);
  vist[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    int x = u / (n * m), z = u % m, y = (u - (x * n * m)) / m;
    for (int i = 0; i < 6; i++) {
      int tx = x + dir[i][0], ty = y + dir[i][1], tz = z + dir[i][2];
      if (tx >= 0 && tx < l && ty >= 0 && ty < n && tz >= 0 && tz < m) {
        int v = tx * n * m + ty * m + tz;
        if (vist[v] || mat[v] == -2) continue;
        vist[v] = 1;
        q.push(v);
        d[idx[s]][v] = d[idx[s]][u] + 1;
      }
    }
  }
}

int main() {
  giii(n, m, l);
  mat.resize(n * m * l);
  int s;
  REP(i, 0, l) {
    REP(j, 0, n) {
      REP(k, 0, m) {
        gi(mat[i * n * m + j * m + k]);
        if (mat[i * n * m + j * m + k] == -1)
          s = i * n * m + j * m + k;
        else if (mat[i * n * m + j * m + k] > 0)
          b.push_back(i * n * m + j * m + k);
      }
    }
  }
  memset(d, inf, sizeof d);
  idx[s] = 0;
  int cnt = 1;
  REP(i, 0, b.size()) idx[b[i]] = cnt++;
  sp(s);
  REP(i, 0, b.size()) { sp(b[i]); }
  vi gb;
  gb.push_back(s);
  REP(i, 0, b.size()) {
    if (d[idx[s]][b[i]] != inf) gb.push_back(b[i]);
  }
  int f[3300][13]{};
  memset(f, inf, sizeof f);
  REP(i, 0, gb.size()) f[0][0] = 0;
  for (int i = 0; i < (1 << gb.size()); i++) {
    REP(j, 0, gb.size()) {
      if (f[i][j] == inf) continue;
      REP(k, 0, gb.size()) {
        if (i & (1 << k)) continue;
        f[i | (1 << k)][k] = min(f[i | (1 << k)][k], f[i][j] + d[idx[gb[j]]][gb[k]]);
      }
    }
  }
  int len = inf;
  REP(i, 1, gb.size()) {
    len = min(len, f[(1 << gb.size()) - 1][i] + d[idx[gb[i]]][gb[0]]);
  }
  int val = 0;
  REP(i, 1, gb.size()) { val += mat[gb[i]]; }
  printf("%d %d\n", val, (val == 0 ? 0 : len));
  return 0;
}
