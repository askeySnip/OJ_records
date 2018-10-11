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
int r, c, m, n;
int vist[103][103];
int even, odd;
int dirx[8], diry[8];
void dfs(int x, int y) {
  int counts = 0;
  vist[x][y] = 1;
  map<pair<int, int>, int > mp;
  for(int i=0; i<8; i++) {
    int tx = x + dirx[i], ty = y + diry[i];
    if(tx<0 || tx>=r || ty<0 || ty>=c || vist[tx][ty] == -1) continue;
    if(mp.find(make_pair(tx, ty)) == mp.end()) {
      counts++;
      mp[make_pair(tx, ty)] = 1;
      if(vist[tx][ty] == 1) continue;
      dfs(tx, ty);
    }
  }
  if(counts%2) odd++;
  else even++;
}
int main() {
  int t;
  scanf("%d", &t);
  for(int i=0; i<t; i++) {
    scanf("%d%d%d%d", &r, &c, &m, &n);
    dirx[0] = m; dirx[1] = -m; dirx[2] = n; dirx[3] = -n; dirx[4] = m; dirx[5] = -m; dirx[6] = n; dirx[7] = -n;
    diry[0] = n; diry[1] = n; diry[2] = m; diry[3] = m; diry[4] = -n; diry[5] = -n; diry[6] = -m; diry[7] = -m;
    int w, x, y;
    scanf("%d", &w);
    memset(vist, 0, sizeof vist);
    for(int j=0; j<w; j++) {
      scanf("%d%d", &x, &y);
      vist[x][y] = -1;
    }
    even = 0; odd = 0;
    dfs(0, 0);
    printf("Case %d: %d %d\n", i+1, even, odd);
  }
}
