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

// struct
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;
struct pos {
  int height;
  int x, y;
  pos(int h_, int x_, int y_) : height(h_), x(x_), y(y_) {}
  bool operator>(pos a) const { return height > a.height; }
  bool operator<(pos a) const { return height < a.height; }
};

// data
int r, c;
int h[60][60];
int vist[60][60];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int solve() {
  memset(vist, 0, sizeof vist);
  priority_queue<pos, vector<pos>, greater<pos>> pq;
  for (int i = 0; i < c; i++) pq.push(pos(h[0][i], 0, i)), vist[0][i] = 1;
  for (int i = 1; i < r - 1; i++)
    pq.push(pos(h[i][0], i, 0)),
        vist[i][0] = 1, pq.push(pos(h[i][c - 1], i, c - 1)), vist[i][c - 1] = 1;
  for (int i = 0; i < c; i++)
    pq.push(pos(h[r - 1][i], r - 1, i)), vist[r - 1][i] = 1;
  int cur_height = pq.top().height;
  int ans = 0;
  while (!pq.empty()) {
    pos cur = pq.top();
    pq.pop();
    cur_height = cur.height;
    queue<pos> q;
    q.push(cur);
    while (!q.empty()) {
      pos tmp = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int tx = tmp.x + dx[i], ty = tmp.y + dy[i];
        if (tx >= 0 && tx < r && ty >= 0 && ty < c && !vist[tx][ty]) {
          vist[tx][ty] = 1;
          if (h[tx][ty] <= cur_height) {
            ans += cur_height - h[tx][ty];
            q.push(pos(h[tx][ty], tx, ty));
          } else {
            pq.push(pos(h[tx][ty], tx, ty));
          }
        }
      }
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &r, &c);
    REP(i, 0, r) {
      REP(j, 0, c) { scanf("%d", &h[i][j]); }
    }
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
