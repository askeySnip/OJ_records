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
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n, m, q;
int t[210];
int dist[210][210];

void update(int k) {
  for(int i=0; i<n; i++) {
    REP(j, 0, n) {
      if(dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[j][i] = dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
}

int main() {
  memset(dist, inf, sizeof dist);
  scanf("%d%d", &n, &m);
  REP(i, 0, n) scanf("%d", &t[i]), dist[i][i] = 0;
  int u, v, w;
  REP(i, 0, m) {
    scanf("%d%d%d", &u, &v, &w);
    dist[u][v] = dist[v][u] = w;
  }
  scanf("%d", &q);
  int x, y, tm, now = 0;
  REP(i, 0, q) {
    scanf("%d%d%d", &x, &y, &tm);
    while(now < n && t[now] <= tm) {
      update(now);
      now++;
    }
    if(t[x] > tm || t[y] > tm) printf("-1\n");
    else {
      printf("%d\n", dist[x][y] == inf ? -1 : dist[x][y]);
    }
  }
  return 0;
}
