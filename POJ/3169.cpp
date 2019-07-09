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
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n, ml, md;
vii edges[1024];
int dist[1024];
// 差分约束系统转最短路问题

void solve() {
  fill(dist, dist+n+1, inf);
  dist[1] = 0;
  REP(i, 0, n) {
    REP(j, 1, n+1) {
      REP(k, 0, edges[j].size()) {
        ii v = edges[j][k];
        if(dist[v.first] > dist[j] + v.second) dist[v.first] = dist[j]+v.second;
      }
    }
  }
  int res = dist[n];
  if(dist[1] < 0) {
    res = -1;
  } else if(res == inf) {
    res = -2;
  }
  printf("%d\n", res);
}

int main() {
  scanf("%d %d %d", &n, &ml, &md);
  int a, b, d;
  REP(i, 0, ml) {
    scanf("%d %d %d", &a, &b, &d);
    edges[a].push_back(ii(b, d));
  }
  REP(i, 0, md) {
    scanf("%d %d %d", &a, &b, &d);
    edges[b].push_back(ii(a, -d));
  }
  REP(i, 2, n+1) {
    edges[i].push_back(ii(i-1, 0));
  }
  solve();
  return 0;
}
