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

int n;
vi edges[200024];
ll ans;
ll dp[200024];
int siz[200024];

int calcsize(int v, int p = -1) {
  siz[v] = 1;
  for (int i=0; i<(int)edges[v].size(); i++) {
    int to = edges[v][i];
    if (to == p) continue;
    siz[v] += calcsize(to, v);
  }
  return siz[v];
}

long long calcdp(int v, int p = -1) {
  dp[v] = siz[v];
  for (int i=0; i<(int)edges[v].size(); i++) {
    int to = edges[v][i];
    if (to == p) continue;
    dp[v] += calcdp(to, v);
  }
  return dp[v];
}

void dfs(int v, int p = -1) {
  ans = max(dp[v], ans);

  for(int i=0; i<(int)edges[v].size(); i++) {
    int to = edges[v][i];
    if(to == p) continue;

    dp[v] -= dp[to];
    dp[v] -= siz[to];
    siz[v] -= siz[to];
    siz[to] += siz[v];
    dp[to] += siz[v];
    dp[to] += dp[v];

    dfs(to, v);

    dp[to] -= dp[v];
    dp[to] -= siz[v];
    siz[to] -= siz[v];
    siz[v] += siz[to];
    dp[v] += siz[to];
    dp[v] += dp[to];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  int a, b;
  for(int i=0; i<n-1; i++) {
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  ans = 0L;
  memset(dp, 0, sizeof dp);
  calcsize(1);
  calcdp(1);
  dfs(1);
  cout << ans << endl;
  return 0;
}
