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
const int inf = 0x3fffffff;
const int mod = 1e9 + 7;

// struct

// data
int n, m, p;
int coin[1024][1024], cost[1024], f[2][1024][1024];

int pre(int x) {
  x--;
  return x ? x : n;
}

int main() {
  scanf("%d%d%d", &n, &m, &p);
  REP(i, 1, n + 1) { REP(j, 1, m + 1) scanf("%d", &coin[i][j]); }
  REP(i, 1, n + 1) scanf("%d", &cost[i]);
  int mx0 = -inf, mx = -inf, no = 1;
  REP(i, 1, n + 1)
  f[0][1][i] = coin[i][1] - cost[i], mx0 = mx = max(mx, f[0][1][i]);
  REP(t, 2, m + 1) {
    REP(st, 1, n + 1) {
      f[no][1][st] = mx0 + coin[st][t] - cost[st], mx = max(mx, f[no][1][st]);
      for (int cur = 2; cur <= p && cur <= t; cur++)
        f[no][cur][st] = f[1 - no][cur - 1][pre(st)] + coin[st][t],
        mx = max(mx, f[no][cur][st]);
    }
    mx0 = mx;
    mx = -inf;
    no = 1 - no;
  }
  printf("%d\n", mx0);
  return 0;
}
