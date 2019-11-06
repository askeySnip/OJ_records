/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const ll inf = 1e9;
const int mod = 1e9 + 7;

int n, m, k;
char g[110][110];
int dp[110][110][110];
int height[110][110];

bool check(int x, int l, int r) {
  for (int i = l; i <= r; i++) {
    if (g[x][i] != '#') return false;
  }
  return true;
}

int solve() {
  memset(dp, 0, sizeof dp);
  memset(height, 0, sizeof height);
  int ans = 0;
  REP(i, 0, n) {
    REP(j, 0, m) {
      int cnt = 0;
      for (int r = i; r < n; r++) {
        int h = r - i, left = j - h, right = j + h;
        if (left < 0 || right >= m) break;
        if (check(r, left, right))
          cnt++;
        else
          break;
      }
      height[i][j] = cnt;
      // cout << i << " " << j << " " << height[i][j] << endl;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < m; j++) {
      if (height[i][j] == 0) continue;
      for (int v = 1; v <= k; v++) {
        for (int h = 1; h <= height[i][j]; h++) {
          int row = i + h, left = j - h + 1, right = j + h - 1;
          if (v == 1)
            dp[i][j][v] = max(dp[i][j][v], h * h);
          else {
            for (int l = left; l <= right; l++) {
              if (dp[row][l][v - 1] > 0) {
                dp[i][j][v] = max(dp[i][j][v], dp[row][l][v - 1] + h * h);
              }
            }
          }
        }
      }
      ans = max(ans, dp[i][j][k]);
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  // t = 1;
  while (t--) {
    scanf("%d%d%d", &n, &m, &k);
    REP(i, 0, n) { scanf("%s", g[i]); }
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }
  return 0;
}
