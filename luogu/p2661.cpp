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
int T[200024];
int color[200024];
vi path;
int ans;

void dfs(int u) {
  color[u] = 1;
  path.push_back(u);
  if (color[T[u]] == 1) {
    int cnt = 0, n = path.size() - 1;
    while (path[n - cnt] != T[u]) cnt++;
    ans = min(ans, cnt + 1);
  } else if (!color[T[u]])
    dfs(T[u]);
  color[u] = 2;
  path.pop_back();
}

int main() {
  scanf("%d", &n);
  REP(i, 1, n + 1) scanf("%d", &T[i]);
  ans = inf;
  for (int i = 1; i <= n; i++) {
    if (!color[i]) dfs(i);
  }
  printf("%d\n", ans);
  return 0;
}
