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
int n, c;
int dp[2][55][55];
int s[55][55];
int p[55], w[55];

int main() {
  scanf("%d%d", &n, &c);
  c--;
  REP(i, 0, n) scanf("%d%d", &p[i], &w[i]);
  REP(i, 0, n) REP(j, 0, n) dp[0][i][j] = dp[1][i][j] = inf;
  memset(s, 0, sizeof s);
  REP(i, 0, n) {
    REP(j, i, n) {
      REP(k, 0, i) s[i][j] += w[k];
      REP(k, j + 1, n) s[i][j] += w[k];
    }
  }
  dp[0][c][c] = dp[1][c][c] = 0;
  REP(l, 2, n + 1) {
    REP(i, 0, n - l + 1) {
      int j = i + l - 1;
      dp[0][i][j] =
          min(dp[0][i][j], dp[0][i + 1][j] + (p[i + 1] - p[i]) * s[i + 1][j]);
      dp[0][i][j] =
          min(dp[0][i][j], dp[1][i + 1][j] + (p[j] - p[i]) * s[i + 1][j]);
      dp[0][i][j] =
          min(dp[0][i][j], dp[0][i][j - 1] + (p[j] - p[i]) * s[i][j - 1] +
                               (p[j] - p[i]) * s[i][j]);
      dp[0][i][j] =
          min(dp[0][i][j], dp[1][i][j - 1] + (p[j] - p[j - 1]) * s[i][j - 1] +
                               (p[j] - p[i]) * s[i][j]);
      dp[1][i][j] =
          min(dp[1][i][j], dp[1][i + 1][j] + (p[j] - p[i]) * s[i + 1][j] +
                               (p[j] - p[i]) * s[i][j]);
      dp[1][i][j] =
          min(dp[1][i][j], dp[0][i + 1][j] + (p[i + 1] - p[i]) * s[i + 1][j] +
                               (p[j] - p[i]) * s[i][j]);
      dp[1][i][j] =
          min(dp[1][i][j], dp[0][i][j - 1] + (p[j] - p[i]) * s[i][j - 1]);
      dp[1][i][j] =
          min(dp[1][i][j], dp[1][i][j - 1] + (p[j] - p[j - 1]) * s[i][j - 1]);
    }
  }
  printf("%d\n", min(dp[0][0][n - 1], dp[1][0][n - 1]));
  return 0;
}
