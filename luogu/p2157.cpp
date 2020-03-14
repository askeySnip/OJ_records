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
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
#define Nm(i) (i + 8)

// struct

// data
int n;
int t[1024], b[1024];
int dp[1024][1 << 8][20];

void solve() {
  memset(dp, 0x3f, sizeof dp);
  dp[1][0][Nm(-1)] = 0;
  t[0] = 0;
  REP(i, 1, n + 1) {
    REP(j, 0, 1 << 8) {
      REP(k, -8, 8) {
        if (dp[i][j][Nm(k)] == inf) continue;
        if (j & 1) {
          dp[i + 1][j >> 1][Nm(k - 1)] =
              min(dp[i + 1][j >> 1][Nm(k - 1)], dp[i][j][Nm(k)]);
        } else {
          int r = inf;
          REP(l, 0, 8) {
            if (j & (1 << l)) continue;
            if (i + l > r) break;
            r = min(r, i + l + b[i + l]);
            dp[i][j | (1 << l)][Nm(l)] =
                min(dp[i][j | (1 << l)][Nm(l)],
                    dp[i][j][Nm(k)] + (i + k ? t[i + k] ^ t[i + l] : 0));
          }
        }
      }
    }
  }
  int ans = inf;
  REP(k, -8, 1) ans = min(ans, dp[n][1][Nm(k)]);
  printf("%d\n", ans);
}

int main() {
  int kase;
  scanf("%d", &kase);
  while (kase--) {
    scanf("%d", &n);
    REP(i, 1, n + 1) scanf("%d%d", &t[i], &b[i]);
    solve();
  }
  return 0;
}
