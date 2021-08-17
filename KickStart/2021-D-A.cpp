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
int m[3][3];
inline bool heng(int i) { return m[i][0] - m[i][1] == m[i][1] - m[i][2]; }
inline bool shu(int i) { return m[0][i] - m[1][i] == m[1][i] - m[2][i]; }
inline bool ld() { return m[0][0] - m[1][1] == m[1][1] - m[2][2]; }
inline bool rd() { return m[0][2] - m[1][1] == m[1][1] - m[2][0]; }
int main() {
  int t, kase = 0;
  gi(t);
  while (t--) {
    giii(m[0][0], m[0][1], m[0][2]);
    gii(m[1][0], m[1][2]);
    giii(m[2][0], m[2][1], m[2][2]);
    int d, cnt = 0;
    if (abs(m[1][0] - m[1][2]) % 2 == 0) {
      d = (m[1][2] - m[1][0]) / 2;
      m[1][1] = m[1][0] + d;
      int cntt = 1;
      if (shu(1)) ++cntt;
      if (ld()) ++cntt;
      if (rd()) ++cntt;
      if (cntt > cnt) cnt = cntt;
    }
    if (abs(m[0][1] - m[2][1]) % 2 == 0) {
      d = (m[2][1] - m[0][1]) / 2;
      m[1][1] = m[0][1] + d;
      int cntt = 1;
      if (heng(1)) ++cntt;
      if (ld()) ++cntt;
      if (rd()) ++cntt;
      if (cntt > cnt) cnt = cntt;
    }
    if (abs(m[0][0] - m[2][2]) % 2 == 0) {
      d = (m[2][2] - m[0][0]) / 2;
      m[1][1] = m[0][0] + d;
      int cntt = 1;
      if (heng(1)) ++cntt;
      if (shu(1)) ++cntt;
      if (rd()) ++cntt;
      cnt = max(cnt, cntt);
    }
    if (abs(m[0][2] - m[2][0]) % 2 == 0) {
      d = (m[2][0] - m[0][2]) / 2;
      m[1][1] = m[0][2] + d;
      int cntt = 1;
      if (heng(1)) ++cntt;
      if (shu(1)) ++cntt;
      if (ld()) ++cntt;
      cnt = max(cnt, cntt);
    }
    if (heng(0)) ++cnt;
    if (heng(2)) ++cnt;
    if (shu(0)) ++cnt;
    if (shu(2)) ++cnt;
    printf("Case #%d: %d\n", ++kase, cnt);
  }
  return 0;
}
