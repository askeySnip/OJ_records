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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
vii adj[100010];
int n, m, s;
int dis[100010];

void dijkstra() {
  priority_queue<ii, vii, greater<ii>> pq;
  pq.push({0, s});
  while (!pq.empty()) {
    ii p = pq.top();
    pq.pop();
    if (p.first > dis[p.second]) continue;
    for (auto v : adj[p.second]) {
      if (dis[p.second] + v.second < dis[v.first]) {
        dis[v.first] = dis[p.second] + v.second;
        pq.push({dis[v.first], v.first});
      }
    }
  }
  REP(i, 1, n) printf("%d ", dis[i]);
  printf("%d\n", dis[n]);
}

int main() {
  scanf("%d%d%d", &n, &m, &s);
  int u, v, w;
  REP(i, 0, m) {
    scanf("%d%d%d", &u, &v, &w);
    adj[u].push_back({v, w});
  }
  memset(dis, inf, sizeof dis);
  dis[s] = 0;
  dijkstra();
  return 0;
}
