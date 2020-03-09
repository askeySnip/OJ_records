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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct

// data
int n, m;
int a[510][510];
bool vist[510][510];
int l[510][510], r[510][510];

int dirx[] = {0, 0, 1, -1};
int diry[] = {-1, 1, 0, 0};

void dfs(int x, int y) {
  vist[x][y] = 1;
  REP(i, 0, 4) {
    int tx = dirx[i] + x, ty = diry[i] + y;
    if (tx >= 0 && tx < n && ty >= 0 && ty < m) {
      if (a[x][y] <= a[tx][ty]) continue;
      if (!vist[tx][ty]) dfs(tx, ty);
      l[x][y] = min(l[x][y], l[tx][ty]);
      r[x][y] = max(r[x][y], r[tx][ty]);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, n) { REP(j, 0, m) scanf("%d", &a[i][j]); }
  memset(vist, 0, sizeof vist);
  memset(r, 0, sizeof r);
  REP(i, 0, n) REP(j, 0, m) l[i][j] = inf;
  REP(i, 0, m) l[n - 1][i] = r[n - 1][i] = i;
  REP(i, 0, m) {
    if (!vist[0][i]) dfs(0, i);
  }
  int cnt = 0;
  REP(i, 0, m) {
    if (!vist[n - 1][i]) cnt++;
  }
  if (cnt) {
    printf("0\n%d\n", cnt);
  } else {
    int left = 0;
    while (left < m) {
      int maxr = 0;
      REP(i, 0, m) {
        if (l[0][i] <= left) maxr = max(maxr, r[0][i]);
      }
      cnt++;
      left = maxr + 1;
    }
    printf("1\n%d\n", cnt);
  }
  return 0;
}
