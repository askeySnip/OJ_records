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
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int r, c;
vector<vi> grid;
vector<vi> nxt[4];

bool check(int i, int j) {
  int t = 0, cnt = 0;
  if (nxt[0][i][j] >= 0) t += grid[nxt[0][i][j]][j], cnt++;
  if (nxt[1][i][j] < r) t += grid[nxt[1][i][j]][j], cnt++;
  if (nxt[2][i][j] >= 0) t += grid[i][nxt[2][i][j]], cnt++;
  if (nxt[3][i][j] < c) t += grid[i][nxt[3][i][j]], cnt++;
  if (grid[i][j] * cnt < t) {
    return true;
  }
  return false;
}

void deal(int i, int j) {
  if (nxt[0][i][j] >= 0) {
    int ii = nxt[0][i][j];
    nxt[1][ii][j] = nxt[1][i][j];
  }
  if (nxt[1][i][j] < r) {
    int ii = nxt[1][i][j];
    nxt[0][ii][j] = nxt[0][i][j];
  }
  if (nxt[2][i][j] >= 0) {
    int jj = nxt[2][i][j];
    nxt[3][i][jj] = nxt[3][i][j];
  }
  if (nxt[3][i][j] < c) {
    int jj = nxt[3][i][j];
    nxt[2][i][jj] = nxt[2][i][j];
  }
}

void solve() {
  ll ans = 0;
  ll sum = 0;
  REP(i, 0, r) {
    REP(j, 0, c) {
      nxt[0][i][j] = i - 1;
      nxt[1][i][j] = i + 1;
      nxt[2][i][j] = j - 1;
      nxt[3][i][j] = j + 1;
      sum += grid[i][j];
    }
  }
  vii ch;
  vector<vi> when(r, vi(c, -1));
  int iter = 0;
  ans += sum;
  REP(i, 0, r) {
    REP(j, 0, c) {
        ch.emplace_back(i, j);
    }
  }
  for(int iter = 0; ; iter++) {
    vii rm;
    for(auto i : ch) {
      if(check(i.first, i.second)) rm.push_back(i);
    }
    if(rm.empty()) break;
    for(auto i : rm) {
      when[i.first][i.second] = iter;
      sum -= grid[i.first][i.second];
    }
    ans += sum;
    vii new_check;
    for(auto x : rm) {
      int i=x.first, j=x.second;
      int ii, jj;
      if(nxt[0][i][j] >= 0) {
        ii = nxt[0][i][j];
        if(when[ii][j] != iter) new_check.emplace_back(ii, j);
        when[ii][j] = iter;
      }
      if (nxt[1][i][j] < r) {
        ii = nxt[1][i][j];
        if (when[ii][j] != iter) new_check.emplace_back(ii, j);
        when[ii][j] = iter;
      }
      if (nxt[2][i][j] >= 0) {
        jj = nxt[2][i][j];
        if (when[i][jj] != iter) new_check.emplace_back(i, jj);
        when[i][jj] = iter;
      }
      if (nxt[3][i][j] < c) {
        jj = nxt[3][i][j];
        if (when[i][jj] != iter) new_check.emplace_back(i, jj);
        when[i][jj] = iter;
      }
    }
    for(auto x : rm) {
      deal(x.first, x.second);
    }
    swap(new_check, ch);
  }
  printf("%lld\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &r, &c);
    grid.assign(r, vi(c, 0));
    for (int i = 0; i < 4; i++) nxt[i].assign(r, vi(c, 0));
    REP(i, 0, r) REP(j, 0, c) scanf("%d", &grid[i][j]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
