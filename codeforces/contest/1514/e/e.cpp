/*
AUTHOR: lz.askey
CREATED: 20.04.2021 21:45:30
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

bool oneEdge(int a, int b) {
  printf("1 %d %d\n", a, b);
  fflush(stdout);
  int ret;
  gi(ret);
  if (ret == -1) exit(0);
  return ret;
}

bool manyEdges(int x, vi s) {
  printf("2 %d %d", x, sz(s));
  for (int& i : s) printf(" %d", i);
  printf("\n");
  fflush(stdout);
  int ret;
  gi(ret);
  if (ret == -1) exit(0);
  return ret;
}

vi getPrefix(vi& path, int p) {
  vi ret;
  REP(i, 0, p + 1) ret.push_back(path[i]);
  return ret;
}

vector<vi> getMap() {
  vector<vi> ret(n, vi(n, 1));
  vi path;
  REP(i, 0, n) path.push_back(i);
  stable_sort(all(path), oneEdge);
  int p = n - 2;
  for (int i = n - 1; i >= 0; i--) {
    if (p == i) {
      REP(j, 0, i + 1) {
        REP(k, i + 1, n) { ret[path[k]][path[j]] = 0; }
      }
      p--;
    }
    while (manyEdges(path[i], getPrefix(path, p))) p--;
  }
  return ret;
}

void solve() {
  auto res = getMap();
  puts("3");
  REP(i, 0, n) {
    REP(j, 0, n) { printf("%d", res[i][j]); }
    printf("\n");
  }
  fflush(stdout);
}

int main() {
  int t;
  gi(t);
  while (t--) {
    gi(n);
    solve();
    int ok;
    gi(ok);
    if (ok == -1) return 0;
  }
  return 0;
}
