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

// data
int n, m, q, l, a[1000010], b;
ll sm[1000010];

void Modify(int i, int val) {
  a[i] = val;
  sm[i += n] = val;
  for (; i; i >>= 1) {
    sm[i >> 1] = sm[i] + sm[i ^ 1];
  }
}

ll g(int l, int r) {
  ll rt = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) rt += sm[l++];
    if (r & 1) rt += sm[--r];
  }
  return rt;
}

ll sum(int i) {
  ll tot = 0;
  while (i > 0) {
    int lg = __builtin_ctz(i);
    i -= i & -i;
    int le = i ^ b;
    le &= ((n - 1) - ((1 << lg) - 1));
    tot += g(le, le + (1 << lg));
  }
  return tot;
}

int main() {
  b = 0;
  getII(l, q);
  n = 1 << l;
  REP(i, 0, n) {
    getI(a[i]);
    sm[i + n] = a[i];
  }
  for (int i = n - 1; i; i--) {
    sm[i] = sm[i << 1] + sm[(i << 1) + 1];
  }

  for (; q--;) {
    int m;
    getI(m);
    if (m == 1) {
      int k, x;
      getII(x, k);
      x = (x - 1) ^ b;
      Modify(x, k);
    } else if (m == 2) {
      int k;
      getI(k);
      b ^= (1 << k) - 1;
    } else if (m == 3) {
      int k;
      getI(k);
      b ^= (1 << k);
    } else {
      int l, r;
      getII(l, r);
      ll tot = sum(r) - sum(l - 1);
      printf("%lld\n", tot);
    }
  }

  return 0;
}
