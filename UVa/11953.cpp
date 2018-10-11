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
int n;
char graph[103][103];
int counts[103];
int color[103][103];
int dirx[4] = {0, 1};
int diry[4] = {1, 0};
int dfs(int x, int y, int id) {
  color[x][y] = id;
  int ret = 1;
  if(graph[x][y] == 'x') counts[id] = 1;
  for(int i=0; i<2; i++) {
    int tx = x + dirx[i];
    int ty = y + diry[i];
    if(tx>=0 && tx<n && ty>=0 && ty<n && graph[tx][ty] != '.' && color[tx][ty] == 0){
      ret += dfs(tx, ty, id);
    }
  }
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  for(int kase = 1; kase<=t; kase++) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%s", graph[i]);
    memset(counts, 0, sizeof counts);
    memset(color, 0, sizeof color);
    int color_num = 1;
    int ans = 0;
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(color[i][j] || graph[i][j] == '.') continue;
        int l = dfs(i, j, color_num);
        if(l > n/2) counts[color_num] = 0;
        color_num++;
      }
    }
    for(int i=1; i<=color_num; i++) ans += counts[i];
    printf("Case %d: %d\n", kase, ans);
  }
  return 0;
}
