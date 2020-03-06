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
int m, n;
int a[51][51];
int dp[51][51][51][51];

int dfs(int x1, int y1, int x2, int y2) {
  if (x1 == m - 1 && y1 == n - 1 && x2 == m - 1 && y2 == n - 1) return 0;
  if (x1 == x2 && y1 == y2) return -inf;
  if (dp[x1][y1][x2][y2]) return dp[x1][y1][x2][y2];
  int c = a[x1][y1] + a[x2][y2];
  int ret = 0;
  if (x1 + 1 < m) {
    if (x2 + 1 < m) ret = max(ret, dfs(x1 + 1, y1, x2 + 1, y2));
    if (y2 + 1 < n) ret = max(ret, dfs(x1 + 1, y1, x2, y2 + 1));
  }
  if (y1 + 1 < n) {
    if (x2 + 1 < m) ret = max(ret, dfs(x1, y1 + 1, x2 + 1, y2));
    if (y2 + 1 < n) ret = max(ret, dfs(x1, y1 + 1, x2, y2 + 1));
  }
  return dp[x1][y1][x2][y2] = ret + c;
}

int main() {
  scanf("%d%d", &m, &n);
  REP(i, 0, m) REP(j, 0, n) scanf("%d", &a[i][j]);
  memset(dp, 0, sizeof dp);
  dfs(0, 1, 1, 0);
  printf("%d\n", dp[0][1][1][0]);
  return 0;
}
