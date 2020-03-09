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
int n;
int state[5][8], t_state[6][5][8], vist[5][8];
vector<tuple<int, int, int>> path;
bool f;

void copy(int x) { REP(i, 0, 5) REP(j, 0, 7) t_state[x][i][j] = state[i][j]; }

bool check() {
  REP(i, 0, 5) if (state[i][0]) return false;
  return true;
}

void update() {
  REP(i, 0, 5) {
    int t = 0;
    REP(j, 0, 7) {
      if (state[i][j]) state[i][t++] = state[i][j];
    }
    REP(j, t, 7) state[i][j] = 0;
  }
}

bool rm() {
  bool f = false;
  REP(i, 1, 4) {
    REP(j, 0, 7) {
      if (state[i][j] && state[i - 1][j] == state[i][j] &&
          state[i + 1][j] == state[i][j]) {
        vist[i][j] = vist[i - 1][j] = vist[i + 1][j] = 1;
        f = true;
      }
    }
  }
  REP(i, 0, 5) {
    REP(j, 1, 6) {
      if (state[i][j] && state[i][j - 1] == state[i][j] &&
          state[i][j + 1] == state[i][j]) {
        vist[i][j] = vist[i][j - 1] = vist[i][j + 1] = 1;
        f = true;
      }
    }
  }
  if (!f) return false;
  REP(i, 0, 5) {
    REP(j, 0, 7) {
      if (vist[i][j]) {
        state[i][j] = 0;
        vist[i][j] = 0;
      }
    }
  }
  return true;
}

void move(int x, int y, int dir) {
  int tx = x + dir;
  swap(state[x][y], state[tx][y]);
  update();
  while (rm()) update();
}

void dfs(int step) {
  if (check()) {
    f = true;
    return;
  }
  if (f || step > n) return;
  copy(step);
  REP(i, 0, 5) {
    REP(j, 0, 7) {
      if (state[i][j]) {
        if (i + 1 < 5 && state[i][j] != state[i + 1][j]) {
          move(i, j, 1);
          path.push_back({i, j, 1});
          dfs(step + 1);
          if (f) return;
          path.pop_back();
          REP(i, 0, 5) {
            REP(j, 0, 7) { state[i][j] = t_state[step][i][j]; }
          }
        }
        if (i && !state[i - 1][j]) {
          move(i, j, -1);
          path.push_back({i, j, -1});
          dfs(step + 1);
          if (f) return;
          path.pop_back();
          REP(i, 0, 5) {
            REP(j, 0, 7) { state[i][j] = t_state[step][i][j]; }
          }
        }
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  memset(state, 0, sizeof state);
  memset(vist, 0, sizeof vist);
  REP(i, 0, 5) {
    int j = 0, c;
    while (scanf("%d", &c), c) state[i][j++] = c;
  }
  f = false;
  dfs(1);
  if (f) {
    REP(i, 0, path.size()) {
      int a, b, c;
      tie(a, b, c) = path[i];
      printf("%d %d %d\n", a, b, c);
    }
  } else
    printf("-1\n");
  return 0;
}
