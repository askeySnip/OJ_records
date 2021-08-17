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
const int N = 5e5 + 10;  // limit for array size
int n, q, p;             // array size

class SegmentTree {
 public:
  ll t[2 * N];

  void build() {
    for (int i = n - 1; i; i--) {
      t[i] = t[i << 1] + t[i << 1 | 1];
    }
  }

  void modify(int pos, ll value) {
    for (t[pos += n] = value; pos > 1; pos >>= 1)
      t[pos >> 1] = t[pos] + t[pos ^ 1];
  }

  ll query(int l, int r) {  // sum of [l, r)
    ll ans = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l & 1) ans += t[l++];
      if (r & 1) ans += t[--r];
    }
    return ans;
  }
};

// ################################### solvtion for test 1
// ############################

// SegmentTree st[4];

// int getfv(int a, int s) {
//   ll x = a, b = a % p, y = b;
//   while (--s) x *= a, y *= b;
//   ll d = x - y;
//   if (d == 0) return 0;
//   int cnt = 0;
//   while (d % p == 0) ++cnt, d /= p;
//   return cnt;
// }

// int main() {
//   int tt, kase = 0;
//   gi(tt);
//   while (tt--) {
//     vi ans;
//     giii(n, q, p);
//     for (int i = 0; i < n; i++) {
//       int a;
//       gi(a);
//       st[0].t[i + n] = getfv(a, 1);
//       st[1].t[i + n] = getfv(a, 2);
//       st[2].t[i + n] = getfv(a, 3);
//       st[3].t[i + n] = getfv(a, 4);
//     }
//     REP(i, 0, 4) st[i].build();
//     REP(i, 0, q) {
//       int tp;
//       gi(tp);
//       if (tp == 1) {
//         int pos, val;
//         gii(pos, val);
//         REP(j, 0, 4) st[j].modify(pos - 1, getfv(val, j + 1));
//       } else {
//         int s, l, r;
//         giii(s, l, r);
//         ans.push_back(st[s - 1].query(l - 1, r));
//       }
//     }
//     printf("Case #%d:", ++kase);
//     REP(i, 0, ans.size()) printf(" %d", ans[i]);
//     printf("\n");
//   }
//   return 0;
// }

// ############################solvtion for test 2###########################

SegmentTree st[4];
ll a[N];

ll fv(ll x) {
  if (x == 0) return 0;
  ll cnt = 0;
  while (x % p == 0) ++cnt, x /= p;
  return cnt;
}

int main() {
  int t, kase = 0;
  gi(t);
  while (t--) {
    giii(n, q, p);
    vector<ll> ans;
    for (int i = 0; i < n; i++) {
      scanf("%lld", &a[i]);
      // notice this special case!!!!!!!!!!!!!
      if (a[i] < p) continue;
      if (a[i] % p == 0) {
        st[0].t[i + n] = fv(a[i]);
      } else {
        st[1].t[i + n] = fv(a[i] - (a[i] % p));
        st[2].t[i + n] = fv(a[i] + (a[i] % p));
        st[3].t[i + n] = 1;
      }
    }
    REP(i, 0, 4) st[i].build();
    REP(i, 0, q) {
      int tp;
      gi(tp);
      if (tp == 1) {
        int pos;
        ll val;
        scanf("%d %lld", &pos, &val);
        if (val < p) {
          REP(j, 0, 4) st[j].modify(pos - 1, 0);
          a[pos - 1] = val;
          continue;
        }
        if (val % p == 0) {
          st[0].modify(pos - 1, fv(val));
          if (a[pos - 1] % p) {
            st[1].modify(pos - 1, 0);
            st[2].modify(pos - 1, 0);
            st[3].modify(pos - 1, 0);
          }
        } else {
          st[1].modify(pos - 1, fv(val - (val % p)));
          st[2].modify(pos - 1, fv(val + (val % p)));
          st[3].modify(pos - 1, 1);
          if (a[pos - 1] % p == 0) st[0].modify(pos - 1, 0);
        }
        a[pos - 1] = val;
      } else {
        ll s;
        int l, r;
        scanf("%lld %d %d", &s, &l, &r);
        ans.push_back(st[0].query(l - 1, r) * s + st[1].query(l - 1, r) +
                      fv(s) * st[3].query(l - 1, r));
        if (p == 2 && s % 2 == 0) {
          ans.back() += st[2].query(l - 1, r) - st[3].query(l - 1, r);
        }
      }
    }
    printf("Case #%d:", ++kase);
    REP(i, 0, ans.size()) printf(" %lld", ans[i]);
    printf("\n");
    REP(i, 0, 4) memset(st[i].t, 0, sizeof(st[i].t));
  }
  return 0;
}