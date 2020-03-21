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
int n, m;
vi adj[10024];
vi color;
bool f;
int ans;

void dfs(int s) {
  queue<int> q;
  q.push(s);
  int cnt = 1, cnt0 = 1;
  while (!q.empty() && f) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (color[v] == inf) {
        color[v] = 1 - color[u];
        q.push(v);
        cnt++;
        if (color[v] == 0) cnt0++;
      } else if (color[v] == color[u]) {
        f = false;
        break;
      }
    }
  }
  if (f) ans += min(cnt0, cnt - cnt0);
}

int main() {
  scanf("%d%d", &n, &m);
  int u, v;
  REP(i, 0, m) {
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  color.assign(n+10, inf);
  f = true;
  ans = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == inf) {
      color[i] = 0;
      dfs(i);
      if (!f) {
        printf("Impossible\n");
        return 0;
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
