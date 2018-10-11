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
const int inf = 1e9;
int xsize, ysize;
int n;
int x[13], y[13];
int dp[13][2100];

inline int dist(int u, int v) {
  return abs(x[u]-x[v]) + abs(y[u]-y[v]);
}

int tsp(int pos, int choosen) {
  if(choosen == (1<<(n+1))-1) return dist(pos, 0);
  if(dp[pos][choosen]) return dp[pos][choosen];
  int ret = inf;
  for(int i=1; i<=n; i++) {
    if(choosen&(1<<i)) continue;
    int val = tsp(i, choosen|(1<<i)) + dist(pos, i);
    if(ret > val) ret = val;
  }
  dp[pos][choosen] = ret;
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &xsize, &ysize);
    scanf("%d %d", &x[0], &y[0]);
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    memset(dp, 0, sizeof dp);
    printf("The shortest path has length %d\n", tsp(0, 1));
  }
  return 0;
}
