/*
AUTHOR: lz.askey
CREATED: 23.07.2021 13:57:23
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
int m, k, ans1, ans2;
ll a[1010][1010], c[1010];
ll x, y;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> k;
  REP(i, 0, k) {
    REP(j, 0, m) {
      cin >> a[i][j];
      c[i] += a[i][j];
    }
  }
  x = (c[k - 1] - c[0]) / (k - 1);
  REP(i, 1, k) {
    if (c[i] - c[0] != x * i) {
      ans1 = i;
      y = c[i] - c[0] - x * i;
      break;
    }
  }
  REP(i, 1, k - 1) {
    if (i - 1 != ans1 && i != ans1 && i + 1 != ans1) {
      x = 0;
      REP(j, 0, m) {
        x += a[i - 1][j] * a[i - 1][j] + a[i + 1][j] * a[i + 1][j] -
             2 * a[i][j] * a[i][j];
      }
      break;
    }
  }
  ll ad = 0, mi = 0;
  REP(j, 0, m) {
    ad += a[ans1 - 1][j] * a[ans1 - 1][j] + a[ans1 + 1][j] * a[ans1 + 1][j];
    mi += a[ans1][j] * a[ans1][j] * 2;
  }
  ad -= x;
  REP(i, 0, m) {
    ll temp = mi - a[ans1][i] * a[ans1][i] * 2 +
              (a[ans1][i] - y) * (a[ans1][i] - y) * 2;
    if (temp == ad) {
      ans2 = a[ans1][i] - y;
      break;
    }
  }
  cout << ans1 << " " << ans2 << "\n";
  return 0;
}
