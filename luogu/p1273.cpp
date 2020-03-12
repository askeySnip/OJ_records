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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct
struct edge {
  int v, w, nxt;
};

// data
int n, m;
edge e[10000000];
int cnt;
int head[3003], dp[3003][3003], sz[3003];

void add(int u, int v, int w) {
  e[++cnt].v = v;
  e[cnt].w = w;
  e[cnt].nxt = head[u];
  head[u] = cnt;
}

int dfs(int u) {
  if (u > n - m) return sz[u] = 1;
  for (int i = head[u]; i; i = e[i].nxt) {
    sz[u] += dfs(e[i].v);
    for (int j = sz[u]; j >= 0; j--) {
      for (int k = 0; k <= sz[e[i].v]; k++) {
        dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[e[i].v][k] - e[i].w);
      }
    }
  }
  return sz[u];
}

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, n - m) {
    int k, a, c;
    scanf("%d", &k);
    REP(j, 0, k) {
      scanf("%d%d", &a, &c);
      add(i + 1, a, c);
    }
  }
  REP(i, 0, n + 1) REP(j, 0, m + 1) dp[i][j] = -inf;
  REP(i, 1, n + 1) dp[i][0] = 0;
  for (int i = n - m + 1; i <= n; i++) {
    scanf("%d", &dp[i][1]);
  }
  dfs(1);
  for(int i=m; i>=0; i--) {
    if(dp[1][i] >= 0) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
