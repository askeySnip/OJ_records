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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n, m;
int a[2510][2510];
int dp[2510][2510];
int sr[2510][2510];
int sc[2510][2510];

void solve() {
  memset(sr, 0, sizeof sr);
  memset(sc, 0, sizeof sc);
  memset(dp, 0, sizeof dp);
  REP(i, 0, n) REP(j, 1, m) sr[i][j] = (a[i][j - 1] ? 0 : 1 + sr[i][j - 1]);
  REP(i, 0, m) REP(j, 1, n) sc[j][i] = (a[j - 1][i] ? 0 : 1 + sc[j - 1][i]);
  int ans = 0;
  REP(i, 0, n) dp[i][0] = a[i][0], ans = max(ans, a[i][0]);
  REP(i, 0, m) dp[0][i] = a[0][i], ans = max(ans, a[0][i]);
  REP(i, 1, n) {
    REP(j, 1, m) {
      if (a[i][j]) {
        dp[i][j] = min(dp[i - 1][j - 1], min(sr[i][j], sc[i][j])) + 1;
      }
      ans = max(ans, dp[i][j]);
    }
  }
  memset(sr, 0, sizeof sr);
  memset(dp, 0, sizeof dp);
  REP(i, 0, n) dp[i][m - 1] = a[i][m - 1];
  REP(i, 0, m) dp[0][i] = a[n - 1][i];
  REP(i, 0, n) {
    for (int j = m - 2; j >= 0; j--)
      sr[i][j] = (a[i][j + 1] ? 0 : 1 + sr[i][j + 1]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i][j])
        dp[i][j] = min(dp[i - 1][j + 1], min(sr[i][j], sc[i][j])) + 1;
      ans = max(ans, dp[i][j]);
    }
  }
  printf("%d\n", ans);
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    REP(i, 0, n) REP(j, 0, m) scanf("%d", &a[i][j]);
    solve();
  }
  return 0;
}
