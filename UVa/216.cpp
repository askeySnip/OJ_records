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
#define sq(x) ((x) * (x))

const int inf = 1e9;
int n;
int x[10], y[10];
double dis[10][10];
double dp[10][1024];
int par[10][1024];

inline double cacul_dis(int u, int v) {
  return sqrt(sq(x[u] - x[v]) + sq(y[u]-y[v]))+16;
}

double tsp(int pos, int choosen) {
  if(choosen == (1<<n)-1) return 0;
  if(dp[pos][choosen] >= 0) return dp[pos][choosen];
  double temp = inf;
  int tpar = -1;
  for(int i=0; i<n; i++) {
    if(choosen&(1<<i)) continue;
    double val = tsp(i, choosen|(1<<i)) + dis[pos][i];
    if(val < temp) {
      temp = val;
      tpar = i;
    }
  }
  dp[pos][choosen] = temp;
  par[pos][choosen] = tpar;
  return temp;
}

int main() {
  int tc = 1;
  while(scanf("%d", &n), n) {
    for(int i=0; i<n; i++) {
      scanf("%d %d", &x[i], &y[i]);
    }
    for(int i=0; i<n; i++) {
      for(int j=i+1; j<n; j++) {
        dis[i][j] = dis[j][i] = cacul_dis(i, j);
      }
    }
    memset(dp, -1, sizeof dp);
    double minval = inf;
    int idx = -1;
    for(int i=0; i<n; i++) {
      double val = tsp(i, (1<<i));
      if(minval > val) {
        minval = val;
        idx = i;
      }
    }
    printf("**********************************************************\n");
    printf("Network #%d\n", tc++);
    int bitset = 0;
    for(int i=0; i<n-1; i++) {
      bitset |= (1<<idx);
      printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n", x[idx], y[idx], x[par[idx][bitset]], y[par[idx][bitset]], dis[idx][par[idx][bitset]]);
      idx = par[idx][bitset];
    }
    printf("Number of feet of cable required is %.2lf.\n",minval);
  }
  return 0;
}
