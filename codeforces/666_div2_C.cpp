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
  ll a[100010];
  REP(i, 0, n) scanf("%lld", &a[i]);
  if (n == 1) {
    printf("1 1\n");
    printf("%lld\n", -a[0]);
    printf("1 1\n");
    printf("0\n");
    printf("1 1\n");
    printf("0\n");
    return 0;
  }
  printf("1 1\n");
  printf("%lld\n", n - a[0]);
  a[0] = n;
  printf("2 %d\n", n);
  REP(i, 1, n) {
    ll t = 0;
    if (a[i] < 0) t += ((-a[i]) / (n - 1) + 1) * (n - 1);
    a[i] += t;
    t += 1LL * a[i] * (n - 1);
    printf("%lld ", t);
    a[i] += 1LL * a[i] * (n - 1);
  }
  printf("\n");
  printf("1 %d\n", n);
  REP(i, 0, n) { printf("%lld ", -a[i]); }
  printf("\n");
  return 0;
}
