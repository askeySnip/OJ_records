/*
AUTHOR: lz.askey
CREATED: 02.08.2021 23:55:11
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
int boundary(int x1, int y1, int x2, int y2) {
  if (x1 == x2 && y1 == y2) return 0;
  return 2;
}

ll choose(ll n, ll k) {
  if (n < k) return 0ll;
  if (k == 2)
    return n * (n - 1) / 2;
  else
    return n * (n - 1) * (n - 2) / 6;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  ll cnt[2][2] = {0};
  REP(i, 0, n) {
    int x, y;
    cin >> x >> y;
    cnt[(x % 4) / 2][(y % 4) / 2]++;
  }
  ll ans = 0;
  REP(s1, 0, 4) {
    REP(s2, s1, 4) {
      REP(s3, s2, 4) {
        int x1 = s1 / 2, y1 = s1 % 2;
        int x2 = s2 / 2, y2 = s2 % 2;
        int x3 = s3 / 2, y3 = s3 % 2;
        int b = (boundary(x1, y1, x2, y2) + boundary(x1, y1, x3, y3) +
                 boundary(x2, y2, x3, y3)) %
                4;
        if (b == 0) {
          if (s1 == s2 && s2 == s3) {
            ans += choose(cnt[x1][y1], 3);
          } else if (s1 == s2) {
            ans += choose(cnt[x1][y1], 2) * cnt[x3][y3];
          } else if (s2 == s3) {
            ans += choose(cnt[x2][y2], 2) * cnt[x1][y1];
          } else {
            ans += cnt[x1][y1] * cnt[x2][y2] * cnt[x3][y3];
          }
        }
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
