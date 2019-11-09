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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
const double eps = 1e-12;

// data
int n, m, p;
int dist[110][110];
double expt[110];
double pr[1100];

double solve() {
  // using floyd-Warshall
  REP(k, 0, n) {
    REP(i, 0, n) {
      REP(j, 0, n) { dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]); }
    }
  }
  if (n == 2) {
    return 1.0 * p * dist[0][1];
  }
  memset(expt, 0, sizeof expt);
  REP(i, 0, n) {
    REP(j, 0, n) {
      if (j == i) continue;
      expt[i] += dist[i][j];
    }
    expt[i] /= (n - 1);
  }
  pr[0] = 1;
  REP(i, 1, 100) { pr[i] = (1 - pr[i - 1]) / (n - 1); }
  double ans = 0;
  double expt_ = 0;
  REP(i, 1, n) expt_ += expt[i];
  REP(i, 0, min(p, 100)) {
    ans += pr[i] * expt[0];
    ans += (1 - pr[i]) * expt_ / (n - 1);
  }
  if (p >= 100) ans += (p - 100) * (expt_ + expt[0]) / n;
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &p);
    REP(i, 0, 110) REP(j, 0, 110) dist[i][j] = inf;
    REP(i, 0, 110) dist[i][i] = 0;
    int u, v, d;

    REP(i, 0, m) {
      scanf("%d%d%d", &u, &v, &d);
      u--, v--;
      dist[u][v] = dist[v][u] = d;
    }
    printf("Case #%d: %.6f\n", ++kase, solve());
    // solve();
  }

  return 0;
}
