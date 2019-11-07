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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, m;
set<int> g[100010];
set<int> s;

void bfs(int t) {
  queue<int> q;
  q.push(t);
  s.erase(s.find(t));
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto it = s.begin(); it != s.end();) {
      int v = *it;
      if (g[u].find(v) == g[u].end()) {
        it = s.erase(s.find(v));
        q.push(v);
      } else
        it++;
    }
  }
}

void solve() {
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  int cnt = 0;
  REP(i, 1, n + 1) {
    if (s.find(i) != s.end()) {
      cnt++;
      bfs(i);
    }
  }
  printf("%d\n", cnt - 1);
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    int a, b;
    scanf("%d%d", &n, &m);
    REP(i, 0, m) {
      scanf("%d%d", &a, &b);
      g[a].insert(b);
      g[b].insert(a);
    }
    solve();
  }

  return 0;
}
