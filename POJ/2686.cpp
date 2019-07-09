/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n, m, p, a, b;
int t[32];
int d[32][32];
double dp[1 << 8][32];

int main() {
  while(scanf("%d %d %d %d %d", &n, &m, &p, &a, &b), n || m || p || a || b) {
    memset(d, -1, sizeof d);

    REP(i, 0, n) scanf("%d", &t[i]);
    int x, y, z;
    REP(i, 0, p) {
      scanf("%d %d %d", &x, &y, &z);
      x--; y--;
      d[x][y] = z;
      d[y][x] = z;
    }
    REP(i, 0, 1<<n) fill(dp[i], dp[i]+m, inf);
    dp[(1<<n)-1][a-1] = 0;
    double res = inf;
    for(int s = (1<<n) - 1; s>=0; s--) {
      res = min(res, dp[s][b-1]);
      for(int v = 0; v < m; v++) {
        for(int i=0; i<n; i++) {
          if((s >> i) & 1) {
            for(int u = 0; u < m; u++) {
              if(d[v][u] >= 0) {
                dp[s & ~(1 << i)][u] = min(dp[s & ~(1 << i)][u], dp[s][v] + (double)d[v][u] / t[i]);
              }
            }
          }
        }
      }
    }
    if(res == inf) {
      printf("Impossible\n");
    }else {
      printf("%.3f\n", res);
    }
  }
  return 0;
}
