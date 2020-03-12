/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cassert>
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
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3ffffff;
const int mod = 9999973;
// struct

// data
int m, n;
ll f[105][105][105];

inline int C(int x) { return ((x * (x - 1)) / 2) % mod; }

int main() {
  scanf("%d%d", &n, &m);
  f[0][0][0] = 1;
  REP(i, 1, n + 1) {
    REP(j, 0, m + 1) {
      for (int k = 0; j + k <= m; k++) {
        f[i][j][k] = f[i - 1][j][k];
        if (k >= 1) f[i][j][k] += f[i - 1][j + 1][k - 1] * (j + 1);
        if (j >= 1) f[i][j][k] += f[i - 1][j - 1][k] * (m - j - k + 1);
        if (k >= 2) f[i][j][k] += f[i - 1][j + 2][k - 2] * C(j + 2);
        if (k >= 1) f[i][j][k] += f[i - 1][j][k - 1] * j * (m - j - k + 1);
        if (j >= 2) (f[i][j][k] += f[i - 1][j - 2][k] * C(m - j - k + 2));
        f[i][j][k] %= mod;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i <= m; i++)
    for (int j = 0; j <= m; j++) (ans += f[n][i][j]) %= mod;
  printf("%d\n", ans);
  return 0;
}
