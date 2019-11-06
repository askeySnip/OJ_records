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

// struct
#define inf 1e15
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// data
int n, ts, tf;
int s[2010], f[2010], d[2010];
ll dp[2010][2010];

ll check(ll arrive, int start, int freq) {
  if (arrive <= start) return start;
  if ((arrive - start) % freq == 0) return 0;
  ll t = (arrive - start) % freq;
  return freq - t;
}

void solve() {
  memset(dp, 0, sizeof dp);
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[0][i] = inf;
  }
  REP(i, 1, n) {
    REP(j, 0, n) {
      dp[i][j] = (dp[i - 1][j] <= s[i]
                      ? s[i]
                      : check(dp[i - 1][j], s[i], f[i]) + dp[i - 1][j]) +
                 d[i];
      if (j == 0) continue;
      ll t = dp[i - 1][j - 1] + ts;
      dp[i][j] =
          min(dp[i][j], (t <= s[i] ? s[i] : check(t, s[i], f[i]) + t) + d[i]);
    }
  }
  for (int j = n - 1; j >= 0; j--) {
    if (dp[n - 1][j] <= tf) {
      printf("%d\n", j);
      return;
    }
  }
  printf("IMPOSSIBLE\n");
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &ts, &tf);
    REP(i, 1, n) scanf("%d%d%d", &s[i], &f[i], &d[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }

  return 0;
}
