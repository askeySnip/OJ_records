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
struct H {
  int k, l, r;
};

// data
int n, m;
int p = 1048576;
ll l[2100000], r[2100000], z[2100000];
H h[100005], v[200030];

ll sum(int x, int y, int d) {
  if (x <= l[d] && r[d] <= y) return z[d];
  if (x > r[d] || y < l[d]) return 0;
  return sum(x, y, d << 1) + sum(x, y, (d << 1) + 1);
}

void add(int i, ll k) {
  i += p;
  for (z[i] += k; i >>= 1;) {
    z[i] = z[i << 1] + z[(i << 1) + 1];
  }
}

int main() {
  getII(n, m);
  ll s = 1;
  REP(i, 0, p) l[i + p] = r[i + p] = i;
  for (int i = p; --i;) {
    l[i] = l[i << 1];
    r[i] = r[(i << 1) + 1];
  }

  REP(i, 0, n) {
    getIII(h[i].k, h[i].l, h[i].r);
    if (h[i].r - h[i].l == 1000000) s++;
  }

  REP(i, 0, m) {
    int j = i << 1;
    getIII(v[j].k, v[j].l, v[j + 1].l);
    v[j + 1].k = v[j].k;
    v[j].r = 1;
    v[j + 1].r = -1;
    if (v[j + 1].l - v[j].l == 1000000) s++;
  }
  sort(h, h + n, [&](H a, H b) { return a.k < b.k; });
  sort(v, v + 2 * m,
       [&](H a, H b) { return a.l < b.l || a.l == b.l && a.r > b.r; });
  for (int i = 0, j = 0; i < n && j < 2 * m;) {
    if (h[i].k < v[j].l || h[i].k == v[j].l && v[j].r < 0) {
      s += sum(h[i].l, h[i].r, 1);
      i++;
    } else {
      add(v[j].k, v[j].r);
      j++;
    }
  }
  printf("%lld\n", s);
  return 0;
}
