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
#define IN(i, l, r) (l < i && i < r)
#define LINR(i, l, r) (l <= i && i <= r)
#define LIN(i, l, r) (l <= i && i < r)
#define INR(i, l, r) (l < i && i <= r)
#define getI(a) scanf("%d", &a)
#define getII(a, b) scanf("%d%d", &a, &b)
#define getIII(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define getS(x) scanf("%s", x)
#define clr(a, x) memset(a, x, sizeof(a))
#define char2Int(c) (c - '0')
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
set<int> sdouble;
ll sum[2];
set<int> s[2];
int cntdouble[2];

void upd(int id) {
  int x = *s[id].rbegin();
  if (id == 1) x = *s[id].begin();
  bool d = sdouble.count(x);
  sum[id] -= x, sum[!id] += x;
  s[id].erase(x), s[!id].insert(x);
  cntdouble[id] -= d, cntdouble[!id] += d;
}

int main() {
  getI(n);
  REP(i, 0, n) {
    int tp, x;
    getII(tp, x);
    if (x > 0) {
      sum[0] += x;
      s[0].insert(x);
      cntdouble[0] += tp;
      if (tp) sdouble.insert(x);
    } else {
      x = -x;
      int id = 0;
      if (s[1].count(x)) id = 1;
      sum[id] -= x;
      s[id].erase(x);
      cntdouble[id] -= tp;
      if (tp) {
        sdouble.erase(x);
      }
    }

    int sumd = cntdouble[0] + cntdouble[1];
    while (s[1].size() < sumd) upd(0);
    while (s[1].size() > sumd) upd(1);
    while (s[1].size() > 0 && s[0].size() > 0 &&
           *s[0].rbegin() > *s[1].begin()) {
      upd(0);
      upd(1);
    }

    ll ans = sum[0] + sum[1] * 2;
    if (cntdouble[1] == sumd && sumd > 0) {
      ans -= *s[1].begin();
      if (s[0].size() > 0) ans += *s[0].rbegin();
    }
    printf("%lld\n", ans);
  }
  return 0;
}
