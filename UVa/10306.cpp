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
const int INF = 1e9;
int n, m, s;
int dp[50][303][303];
int l[50], r[50];

int solve(int id, int x, int y) {
  if(x*x+y*y == s*s) return 0;
  if(x*x+y*y > s*s) return INF;
  if(id == m) return INF;
  if(dp[id][x][y] != INF) return dp[id][x][y];
  dp[id][x][y] = min(solve(id, x+l[id], y+r[id])+1, solve(id+1, x, y));
  return dp[id][x][y];
}
int main() {
  //  int n, m, s;
  //  int dp[50][303][303];
  scanf("%d", &n);
  while(n--) {
    for(int i=0; i<50; i++) for(int j=0; j<303; j++) for(int k=0; k<303; k++) dp[i][j][k] = INF;
    scanf("%d%d", &m, &s);
    for(int i=0; i<m; i++) {
      scanf("%d%d", &l[i], &r[i]);
    }
    int ans = solve(0, 0, 0);
    if(ans == INF) printf("not possible\n");
    else printf("%d\n", ans);
  }
}
