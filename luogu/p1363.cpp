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
int n, m;
char mt[1600][1600];
int dirx[] = {0, 0, 1, -1};
int diry[] = {1, -1, 0, 0};
int vist[1600][1600][3];
bool f;

void dfs(int x, int y, int lx, int ly) {
  if (f) return;
  if (vist[x][y][0] && (lx != vist[x][y][1] || ly != vist[x][y][2])) {
    f = true;
    return;
  }
  vist[x][y][0] = 1;
  vist[x][y][1] = lx;
  vist[x][y][2] = ly;
  // cout << x << " " << y << " " << lx << " " << ly << endl;
  REP(i, 0, 4) {
    int tx = (x + dirx[i] + n) % n, ty = (y + diry[i] + m) % m;
    int ttx = lx + dirx[i], tty = ly + diry[i];
    if (mt[tx][ty] == '#') continue;
    if (vist[tx][ty][0] == 0 || vist[tx][ty][1] != ttx ||
        vist[tx][ty][2] != tty)
      dfs(tx, ty, ttx, tty);
  }
}

void solve() {
  ii s(0, 0);
  REP(i, 0, n) {
    scanf("%s", mt[i]);
    REP(j, 0, m) if (mt[i][j] == 'S') s = ii(i, j);
  }
  memset(vist, 0, sizeof vist);
  f = false;
  dfs(s.first, s.second, s.first, s.second);
  if (f) {
    printf("Yes\n");
  } else {
    printf("No\n");
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2) {
    solve();
  }
  return 0;
}
