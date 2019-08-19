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
int n, m;
vi edges[200024];
int colored[200024];
int cnt;

void dfs(int u) {
  REP(i, 0, edges[u].size()) {
    int v = edges[u][i];
    if(colored[v] == 0) {
      colored[v] = 3 - colored[u];
      if(colored[v] == 1) cnt++;
      dfs(v);
    }
  }
}
void bipart() {
  REP(i, 1, n+1) colored[i] = 0;
  cnt = 1;
  colored[1] = 1;
  dfs(1);
  int c = 1;
  if(cnt > n / 2) {
    c = 2;
    cnt = n - cnt;
  }
  printf("%d\n", cnt);
  REP(i, 1, n+1) {
    if(colored[i] == c) printf("%d ", i);
  }
  printf("\n");
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  int u, v;
  while(t--) {
    cin >> n >> m;
    REP(i, 0, n+1) edges[i].clear();
    REP(i, 0, m) {
      cin >> v >> u;
      edges[v].push_back(u);
      edges[u].push_back(v);
    }
    bipart();
  }
  return 0;
}
