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
const int maxn = 300000 + 30;
int n;
int w[maxn];
vector<pair<int, ll> > edges[maxn];
ll ans;

ll dfs(int u, int p) {
  vector<ll> path;
  REP(i, 0, edges[u].size()) {
    int v = edges[u][i].first;
    if(v == p) continue;
    ll value = dfs(v, u);
    if(value >= edges[u][i].second) {
      value -= edges[u][i].second;
      path.push_back(value);
    }
  }
  path.push_back(0); path.push_back(0);
  sort(path.begin(), path.end());
  int sz = path.size();
  ans = max(ans, path[sz-1] + path[sz-2] + w[u]);
  return w[u] + path[sz-1];
}

int main() {
  scanf("%d", &n);
  int u, v, c;
  REP(i, 1, n+1) scanf("%d", &w[i]);
  REP(i, 1, n) {
    scanf("%d %d %d", &u, &v, &c);
    edges[u].push_back(make_pair(v, c));
    edges[v].push_back(make_pair(u, c));
  }
  dfs(1, -1);
  printf("%lld\n", ans);
  return 0;
}
