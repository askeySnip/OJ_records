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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const ll inf = 0x3f3f3f3f3f3f;
const int mod = 1e9 + 7;

// struct
struct cmp {
  bool operator()(const pair<int, ii> a, const pair<int, ii> b) {
    return a.first > b.first;
  }
};

// data
int n, m, s, r;
vi e[310];
vi has_stone[310];
vi recipes[310];
ll cost[310][310];
vi cc[310];

void solve() {
  REP(i, 0, r) {
    for (auto st : recipes[i]) cc[st].push_back(i);
  }
  REP(i, 0, n + 1) REP(j, 0, s + 1) cost[i][j] = inf;
  priority_queue<pair<int, ii>, vector<pair<int, ii>>, cmp> pq;
  REP(i, 1, n + 1)
  REP(j, 0, has_stone[i].size()) {
    cost[i][has_stone[i][j]] = 0;
    pq.push({0, {i, has_stone[i][j]}});
  }
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    int u = p.second.first, stone = p.second.second;
    for (auto v : e[u]) {
      if (cost[v][stone] > cost[u][stone] + 1) {
        cost[v][stone] = cost[u][stone] + 1;
        pq.push({cost[v][stone], {v, stone}});
      }
    }
    REP(ii, 0, cc[stone].size()) {
      int i = cc[stone][ii];
      ll t_cost = 0;
      REP(j, 0, recipes[i].size() - 1) t_cost += cost[u][recipes[i][j]];
      if (t_cost < cost[u][recipes[i].back()]) {
        cost[u][recipes[i].back()] = t_cost;
        pq.push({cost[u][recipes[i].back()], {u, recipes[i].back()}});
      }
    }
  }
  ll ans = inf;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, cost[i][1]);
  }
  if (ans >= 1e12) ans = -1;
  printf("%lld\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    int u, v, k;
    scanf("%d%d%d%d", &n, &m, &s, &r);
    REP(i, 0, n + 1) e[i].clear(), has_stone[i].clear();
    REP(i, 0, r + 1) recipes[i].clear();
    REP(i, 0, s + 1) cc[i].clear();
    REP(i, 0, m) {
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    REP(i, 1, n + 1) {
      scanf("%d", &k);
      REP(j, 0, k) scanf("%d", &u), has_stone[i].push_back(u);
    }
    REP(i, 0, r) {
      scanf("%d", &k);
      REP(j, 0, k) scanf("%d", &u), recipes[i].push_back(u);
      scanf("%d", &u);
      recipes[i].push_back(u);
    }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
