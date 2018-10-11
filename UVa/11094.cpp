/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int m, n;
char graph[30][30];
int dirx[4] = {0, 0, 1, -1};
int diry[4] = {1, -1, 0, 0};
int color[30][30];
char land;
int dfs(int x, int y, int id) {
  color[x][y] = id;
  int ret = 1;
  for(int i=0; i<4; i++) {
    int tx = x + dirx[i];
    int ty = (y + diry[i] + n) % n;
    if(tx >=0 && tx < m && color[tx][ty] == 0 && graph[tx][ty] == land)
      ret += dfs(tx, ty, id);
  }
  return ret;
}
int main() {
  while(scanf("%d %d", &m, &n) == 2) {
    for(int i=0; i<m; i++) scanf("%s", graph[i]);
    int x, y;
    scanf("%d %d", &x, &y);
    int id = 0;
    memset(color, 0, sizeof color);
    land = graph[x][y];
    dfs(x, y, ++id);
    int ans = 0;
    for(int i=0; i<m; i++) {
      for(int j=0; j<n; j++) {
        if(color[i][j] || graph[i][j]!=land) continue;
        ans = max(ans, dfs(i, j, ++id));
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
