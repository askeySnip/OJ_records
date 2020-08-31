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

int main() {
  int n;
  getI(n);
  int a[100010];
  REP(i, 0, n) getI(a[i]);
  sort(a, a + n);
  if (n > 32) {
    ll ans = 0;
    REP(i, 0, n) ans += a[i] - 1;
    printf("%lld\n", ans);
  } else {
    ll ans = 1LL * inf * 1000000;
    vector<ll> p(n, 1);
    for (int i = 1;; i++) {
      ll t = 1;
      bool f = true;
      REP(j, 1, n) {
        p[j] = p[j - 1] * i;
        if (p[j] > 1e15) {
          f = false;
          break;
        }
      }
      if (!f) break;
      ll cur = 0;
      REP(j, 0, n) {
        cur += abs(a[j] - p[j]);
        if (cur > ans) break;
      }
      // if (i < 10) cout << i << " " << cur << endl;
      // cout << i << " " << cur << endl;
      if (cur < ans) ans = cur;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
