/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int r, c;
char square[300][300];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int dist[300][300];
vii d[510];

bool check(int k) {
  int add_max = -1000, add_min = 1000, minus_max = -1000, minus_min = 1000;
  for (int i = k + 1; i < 501; i++) {
    if (d[i].empty()) break;
    REP(j, 0, d[i].size()) {
      add_max = max(add_max, d[i][j].first + d[i][j].second);
      add_min = min(add_min, d[i][j].first + d[i][j].second);
      minus_max = max(minus_max, d[i][j].first - d[i][j].second);
      minus_min = min(minus_min, d[i][j].first - d[i][j].second);
    }
  }
  if (add_max == -1000) return true;
  int t = inf;
  REP(i, 0, r) {
    REP(j, 0, c) {
      if (square[i][j] == '0') {
        int d = max(max(abs(i - j - minus_max), abs(i - j - minus_min)),
                    max(abs(i + j - add_max), abs(i + j - add_min)));
        t = min(t, d);
      }
    }
  }
  return t <= k;
}

int solve() {
  queue<pair<ii, int>> q;
  memset(dist, -1, sizeof dist);
  for (int i = 0; i < 510; i++) d[i].clear();
  REP(i, 0, r) {
    REP(j, 0, c) {
      if (square[i][j] == '1') {
        q.push({ii(i, j), 0});
        dist[i][j] = 0;
      }
    }
  }
  while (!q.empty()) {
    ii p = q.front().first;
    int d = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = p.first + dx[i], ty = p.second + dy[i];
      if (tx >= 0 && tx < r && ty >= 0 && ty < c && dist[tx][ty] == -1) {
        dist[tx][ty] = d + 1;
        q.push({ii(tx, ty), d + 1});
      }
    }
  }
  REP(i, 0, r) {
    REP(j, 0, c) { d[dist[i][j]].push_back(ii(i, j)); }
  }
  int l = 0, h = 500, mid;
  while (l < h) {
    mid = (l + h) / 2;
    if (check(mid))
      h = mid;
    else
      l = mid + 1;
  }
  return h;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &r, &c);
    REP(i, 0, r) scanf("%s", square[i]);
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
