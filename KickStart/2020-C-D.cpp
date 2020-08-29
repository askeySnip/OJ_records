/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
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
#define SZ(x) ((int)((x).size()))
#define ALL(c) (c).begin(), (c).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// for debug
inline void pisz(int n) { printf("%d\n", n); }
#define DBG(vari) cerr << #vari << " = " << (vari) << endl;
#define printA(a, L, R) FE(i, L, R) cout << a[i] << (i == R ? '\n' : ' ')
#define printV(a) printA(a, 0, a.size() - 1)
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct
class FenwickTree {
 private:
  vector<ll> ft;

 public:
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  void add(int k, ll v) {
    for (; k < ft.size(); k += k & (-k)) {
      ft[k] += v;
    }
  }

  ll sum(int k) {
    ll ret = 0;
    for (; k; k -= k & (-k)) {
      ret += ft[k];
    }
    return ret;
  }
};
// data
int n, q;

void solve() {
  FenwickTree a(n), b(n);
  vi val(n + 1);
  char type[2];
  int x, v, l, r;
  REP(i, 1, n + 1) {
    getI(v);
    if (i % 2 == 0) v = -v;
    a.add(i, 1LL * v * i);
    b.add(i, 1LL * v);
    val[i] = v;
  }
  ll ans = 0;
  REP(i, 0, q) {
    getS(type);
    if (type[0] == 'U') {
      getII(x, v);
      if (x % 2 == 0) v = -v;
      a.add(x, 1LL * (v - val[x]) * x);
      b.add(x, 1LL * (v - val[x]));
      val[x] = v;
    } else {
      getII(l, r);
      ll t1 = a.sum(r) - a.sum(l - 1);
      ll t2 = b.sum(r) - b.sum(l - 1);
      ll t = t1 - t2 * (l - 1);
      if (l % 2 == 0) t = -t;
      ans += t;
    }
  }
  printf("%lld\n", ans);
}

int main() {
  int t, kase = 0;
  getI(t);
  while (t--) {
    getII(n, q);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
