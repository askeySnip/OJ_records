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
int r, c;
int m[1024][1024];
int u[1024][1024], d[1024][1024], lt[1024][1024], rt[1024][1024];

int main() {
  int t, kase = 1;
  gi(t);
  while (t--) {
    gii(r, c);
    REP(i, 0, r) {
      REP(j, 0, c) {
        gi(m[i][j]);
        u[i][j] = d[i][j] = lt[i][j] = rt[i][j] = 0;
      }
    }
    REP(i, 0, r) {
      REP(j, 1, c) {
        if (m[i][j - 1]) lt[i][j] = lt[i][j - 1] + 1;
      }
      for (int j = c - 2; j >= 0; j--) {
        if (m[i][j + 1]) rt[i][j] = rt[i][j + 1] + 1;
      }
    }
    REP(j, 0, c) {
      REP(i, 1, r) {
        if (m[i - 1][j]) u[i][j] = u[i - 1][j] + 1;
      }
      for (int i = r - 2; i >= 0; i--) {
        if (m[i + 1][j]) d[i][j] = d[i + 1][j] + 1;
      }
    }
    ll ans = 0;
    REP(i, 0, r) {
      REP(j, 1, c) {
        if (!m[i][j]) continue;
        int len_l = lt[i][j] + 1;
        ans += max(0, min(len_l / 2, u[i][j] + 1) - 1);
        ans += max(0, min(d[i][j] + 1, len_l / 2) - 1);
      }
      for (int j = c - 2; j >= 0; j--) {
        if (!m[i][j]) continue;
        int len_l = rt[i][j] + 1;
        ans += max(0, min(len_l / 2, u[i][j] + 1) - 1);
        ans += max(0, min(d[i][j] + 1, len_l / 2) - 1);
      }
    }
    REP(j, 0, c) {
      REP(i, 1, r) {
        if (!m[i][j]) continue;
        int len_l = u[i][j] + 1;
        ans += max(0, min(len_l / 2, lt[i][j] + 1) - 1);
        ans += max(0, min(len_l / 2, rt[i][j] + 1) - 1);
      }
      for (int i = r - 2; i >= 0; i--) {
        if (!m[i][j]) continue;
        int len_l = d[i][j] + 1;
        ans += max(0, min(len_l / 2, lt[i][j] + 1) - 1);
        ans += max(0, min(len_l / 2, rt[i][j] + 1) - 1);
      }
    }
    printf("Case #%d: %lld\n", kase++, ans);
  }
  return 0;
}
