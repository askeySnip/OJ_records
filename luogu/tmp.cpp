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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct
struct node {
  int d, x, y, f;
  node() { d = x = y = f = 0; }
  node(int _d, int _x, int _y, int _f) {
    d = _d;
    x = _x;
    y = _y;
    f = _f;
  }
};

// data
int n, m;
char mz[510][510];
int dist[510][510][6];
int sx, sy, ex, ey;
int dirx[4] = {0, 0, -1, 1};
int diry[4] = {1, -1, 0, 0};

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 1, n + 1) {
    scanf("%s", mz[i] + 1);
    REP(j, 1, m + 1) {
      if (mz[i][j] == 'S') sx = i, sy = j;
      if (mz[i][j] == 'E') ex = i, ey = j;
    }
  }
  memset(dist, inf, sizeof dist);
  queue<node> q;
  dist[sx][sy][5] = 0;
  q.push({0, sx, sy, 5});
  while (!q.empty()) {
    int d, x, y, f;
    d = q.front().d, x = q.front().x, y = q.front().y, f = q.front().f;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = dirx[i] + x, ty = diry[i] + y;
      if (tx > 0 && tx <= n && ty > 0 && ty <= m && mz[tx][ty] != '#') {
        if (dist[tx][ty][f] == inf) {
          dist[tx][ty][f] = d + 1;
          q.push({d + 1, tx, ty, f});
          if (tx == ex && ty == ey) {
            printf("%d\n", d + 1);
            return 0;
          }
        }
      }
    }
    if (f) {
      int tx = n + 1 - x, ty = m + 1 - y;
      if (tx > 0 && tx <= n && ty > 0 && ty <= m && mz[tx][ty] != '#') {
        if (dist[tx][ty][f - 1] == inf) {
          dist[tx][ty][f - 1] = d + 1;
          q.push({d + 1, tx, ty, f - 1});
          if (tx == ex && ty == ey) {
            printf("%d\n", d + 1);
            return 0;
          }
        }
      }
    }
  }
  printf("-1\n");
  return 0;
}
