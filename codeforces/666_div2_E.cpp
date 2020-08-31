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
const ll inf = 0x3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int fx[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const int fxx[8][2] = {{0, 1}, {0, -1}, {1, 0},  {-1, 0},
                       {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

// struct

// data
int n;
ll r1, r2, r3, d;
ll f[1000010];
ll c1[1000010], c2[1000010];

int main() {
  getI(n);
  scanf("%lld%lld%lld", &r1, &r2, &r3);
  scanf("%lld", &d);
  REP(i, 1, n + 1) {
    ll a;
    scanf("%lld", &a);
    c1[i] = r1 * a + r3 + d;
    c2[i] = min({r1 * a + r1 * 2, r2 + r1}) + 2 * d;
  }
  f[n + 1] = 0;
  for (int i = n; i >= 1; i--) {
    f[i] = inf;
    if (i == n - 1) f[i] = min(f[i], c2[i] + c1[i + 1]);
    f[i] = min(f[i], c1[i] + f[i + 1]);
    if (i != n) f[i] = min(f[i], c2[i] + c2[i + 1] + f[i + 2]);
  }
  ll eq = 0;
  for (int i = 1; i <= n; i++) eq += c2[i];
  eq += d;
  f[1] = min(f[1], eq);
  printf("%lld\n", f[1] - d);
  return 0;
}
