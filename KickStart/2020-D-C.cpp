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

// struct

// data
// int n, a, b;
// int father[500010][20];
// double pa[500010], pb[500010];
// int fa[500010], fb[500010];
// void solve() {
//   REP(i, 1, n + 1) pa[i] = pb[i] = 0;
//   REP(i, 1, n + 1) {
//     for (int j = 1; j < 20; j++) {
//       int f = father[i][j - 1];
//       if (f == -1) break;
//       father[i][j] = father[f][j - 1];
//     }
//   }
//   REP(i, 1, n + 1) fa[i] = fb[i] = -1;
//   for (int i = n; i > 0; i--) {
//     int t = i, ta = a, j = 0;
//     while (ta) {
//       if (ta & 1) t = father[t][j];
//       ta /= 2;
//       ++j;
//       if (t == -1) break;
//     }
//     fa[i] = t;
//     t = i, ta = b, j = 0;
//     while (ta) {
//       if (ta & 1) t = father[t][j];
//       ta /= 2;
//       ++j;
//       if (t == -1) break;
//     }
//     fb[i] = t;
//   }
//   for (int i = n; i > 0; i--) {
//     int t = i;
//     while (t != -1) {
//       pa[t] += 1.0 / n;
//       t = fa[t];
//     }
//   }
//   for (int i = n; i > 0; i--) {
//     int t = i;
//     while (t != -1) {
//       pb[t] += 1.0 / n;
//       t = fb[t];
//     }
//   }
//   double ans = 0;
//   for (int i = 1; i <= n; i++) {
//     ans += 1.0 - (1.0 - pa[i]) * (1.0 - pb[i]);
//   }
//   printf("%.7f\n", ans);
// }
int n, a, b;
vi children[500010];
int visits_a[500010], visits_b[500010];
vector<int> path_taken;

void dfs(int u, int va[], int c) {
  path_taken.push_back(u);
  for (auto v : children[u]) {
    dfs(v, va, c);
  }
  path_taken.pop_back();
  va[u] += 1;
  if (path_taken.size() >= c) {
    va[path_taken[path_taken.size() - c]] += va[u];
  }
}

void solve() {
  REP(i, 1, n + 1) visits_a[i] = visits_b[i] = 0;
  dfs(1, visits_a, a);
  dfs(1, visits_b, b);
  double ans = 0;
  REP(i, 1, n + 1) {
    double pa = 1.0 * visits_a[i] / n, pb = 1.0 * visits_b[i] / n;
    ans += pa + pb - pa * pb;
  }
  printf("%.7f\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &a, &b);
    REP(i, 1, n + 1) children[i].clear();
    int u;
    REP(i, 2, n + 1) { scanf("%d", &u), children[u].push_back(i); }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
