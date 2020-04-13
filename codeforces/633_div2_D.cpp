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
int deg[100010];
vi e[100010];
int root;

int get_min() {
  vi dis(n + 1, 0);
  queue<int> q;
  q.push(root);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (auto v : e[cur]) {
      if (dis[v]) continue;
      dis[v] = dis[cur] + 1;
      q.push(v);
    }
  }
  REP(i, 1, n + 1) {
    if (deg[i] == 1) {
      if (dis[i] & 1) return 3;
    }
  }
  return 1;
}

int get_max() {
  int l = 0;
  REP(i, 1, n + 1) if (deg[i] == 1) l++;
  int m = 0;
  REP(i, 1, n + 1) {
    if (deg[i] > 1) {
      for (auto v : e[i]) {
        if (deg[v] == 1) {
          m++;
          break;
        }
      }
    }
  }
  return n - 1 - l + m;
}

void solve() {
  REP(i, 1, n + 1) e[i].clear(), deg[i] = 0;
  int a, b;
  REP(i, 0, n-1) {
    scanf("%d%d", &a, &b);
    ++deg[a];
    ++deg[b];
    e[a].push_back(b);
    e[b].push_back(a);
  }
  REP(i, 1, n + 1) if (deg[i] == 1) {
    root = i;
    break;
  }
  int minf = get_min();
  int maxf = get_max();
  printf("%d %d\n", minf, maxf);
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    solve();
  }
  return 0;
}
