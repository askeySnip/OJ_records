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
int n;
vi g[200010];
int a[200010], b[200010], c[200010];
ll cost = 0;

ii dfs(int u, int par, int mn) {
  ii cnt = {0, 0};
  if(b[u] != c[u]) {
    if(b[u]) cnt.first++;
    else cnt.second++;
  }
  for(auto& it : g[u]) {
    if(it == par) continue;
    ii p  = dfs(it, u, min(mn, a[u]));
    cnt.first += p.first;
    cnt.second += p.second;
  }
  if(a[u] < mn) {
    int take = min(cnt.first, cnt.second);
    cost += 2LL * take * a[u];
    cnt.first -= take;
    cnt.second -= take;
  }
  return cnt;
}

int main() { 
  scanf("%d", &n);
  REP(i, 1, n+1) {
    scanf("%d%d%d", &a[i], &b[i], &c[i]);
  }
  REP(i, 1, n) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ii ans = dfs(1, 0, inf);
  if(ans.first || ans.second) printf("-1\n");
  else printf("%lld\n", cost);
  
  return 0; }
