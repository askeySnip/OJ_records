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

int n, m, e, sr, sc, tr, tc;
int cave[110][110];
int tag[110][110];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int r[1 << 16];
ll rme[1 << 16];
bool exist[1 << 16];
ll dp[1 << 16];
int vist[110][110];
vector<pair<ii, int>> trap;
int trapNum;

void bfs(ll energy, int mask) {
  memset(vist, 0, sizeof vist);
  queue<ii> q;
  bool f = false;
  int remainNum = 0;
  q.push(ii(sr, sc));
  vist[sr][sc] = 1;
  while (!q.empty()) {
    ii p = q.front();
    q.pop();
    // cout <<"queue " << p.first << " " << p.second << endl;
    if (p.first == tr && p.second == tc) f = true;
    for (int i = 0; i < 4; i++) {
      int tx = p.first + dx[i], ty = p.second + dy[i];
      if (tx < 0 || tx >= n || ty < 0 || ty >= m || vist[tx][ty] ||
          cave[tx][ty] == -100000)
        continue;
      if (cave[tx][ty] < 0) {
        remainNum |= (1 << tag[tx][ty]);
        continue;
      }
      energy += cave[tx][ty];
      vist[tx][ty] = 1;
      q.push(ii(tx, ty));
    }
  }
  rme[mask] = energy;
  r[mask] = remainNum;
  exist[mask] = f;
}

ll dfs(int mask) {
  if (dp[mask] != -1) return dp[mask];
  ll ans = -1;
  if (exist[mask]) ans = rme[mask];

  for (int i = 0; i < trapNum; i++) {
    if (r[mask] & (1 << i)) {
      if (trap[i].second + rme[mask] >= 0) {
        ans = max(ans, dfs(mask | (1 << i)));
      }
    }
  }
  dp[mask] = ans;
  return ans;
}

ll solve() {
  trap.clear();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (cave[i][j] < 0 && cave[i][j] != -100000) {
        trap.push_back({{i, j}, cave[i][j]});
        tag[i][j] = trap.size() - 1;
      }
    }
  }
  trapNum = trap.size();
  for (int i = 0; i < (1 << trapNum); i++) {
    ll energy = e;
    for (int j = 0; j < trapNum; j++) {
      if (i & (1 << j)) {
        int x = trap[j].first.first, y = trap[j].first.second;
        cave[x][y] = 0;
        energy += trap[j].second;
      }
    }

    bfs(energy, i);

    for (int j = 0; j < trapNum; j++) {
      if (i & (1 << j)) {
        int x = trap[j].first.first, y = trap[j].first.second;
        cave[x][y] = trap[j].second;
      }
    }
  }
  //    for(int i=0; i<(1<<trapNum); i++) {
  //        printf("%d %d %d\n", r[i], rme[i], exist[i]);
  //    }
  memset(dp, -1, sizeof dp);
  return dfs(0);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d%d%d", &n, &m, &e, &sr, &sc, &tr, &tc);
    sr--;
    sc--;
    tr--;
    tc--;
    REP(i, 0, n) REP(j, 0, m) scanf("%d", &cave[i][j]);
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }
  return 0;
}
