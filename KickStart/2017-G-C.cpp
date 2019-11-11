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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
const double eps = 1e-12;

// data
int n, m;
int g[50][50];
int mem[50][50][50][50];
int min_val[50][50][50][50];

int dp(int t, int p, int l, int r) {
  if (t == p && l == r) return 0;
  if (mem[t][p][l][r]) return mem[t][p][l][r];
  int ans = 0;
  int curr_coin = min_val[t][l][p][r];
  if (t < p) REP(i, t, p)
  ans = max(ans, dp(t, i, l, r) + dp(i + 1, p, l, r) + curr_coin);
  if (l < r) REP(i, l, r)
  ans = max(ans, dp(t, p, l, i) + dp(t, p, i + 1, r) + curr_coin);
  return mem[t][p][l][r] = ans;
}

int solve() {
  memset(min_val, 0, sizeof min_val);
  REP(i, 0, n) {
    REP(j, 0, m) {
      min_val[i][j][i][j] = g[i][j];
      REP(l, j + 1, m)
      min_val[i][j][i][l] = min(min_val[i][j][i][l - 1], g[i][l]);
      REP(l, i + 1, n) {
        min_val[i][j][l][j] = min(min_val[i][j][l - 1][j], g[l][j]);
        REP(k, j + 1, m) {
          min_val[i][j][l][k] = min(min_val[i][j][l][k - 1],
                                    min(g[l][k], min_val[i][j][l - 1][k]));
        }
      }
    }
  }
  memset(mem, 0, sizeof mem);
  return dp(0, n - 1, 0, m - 1);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    REP(i, 0, n) {
      REP(j, 0, m) { scanf("%d", &g[i][j]); }
    }
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }

  return 0;
}
