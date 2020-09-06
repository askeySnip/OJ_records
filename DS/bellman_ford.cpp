#include <bits/stdc++.h>
using namespace std;

void bellman_ford() {
  vector<int> d(n, INF);
  d[v] = 0;
  vector<int> p(n, -1);

  for (;;) {
    bool any = false;
    for (int j = 0; j < m; ++j)
      if (d[e[j].a] < INF)
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = d[e[j].a] + e[j].cost;
          p[e[j].b] = e[j].a;
          any = true;
        }
    if (!any) break;
  }

  if (d[t] == INF)
    cout << "No path from " << v << " to " << t << ".";
  else {
    vector<int> path;
    for (int cur = t; cur != -1; cur = p[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());

    cout << "Path from " << v << " to " << t << ": ";
    for (size_t i = 0; i < path.size(); ++i) cout << path[i] << ' ';
  }
}

// do find a negitive cycle, just do n-th loop
void solve() {
  vector<int> d(n, INF);
  d[v] = 0;
  vector<int> p(n - 1);
  int x;
  for (int i = 0; i < n; ++i) {
    x = -1;
    for (int j = 0; j < m; ++j)
      if (d[e[j].a] < INF)
        if (d[e[j].b] > d[e[j].a] + e[j].cost) {
          d[e[j].b] = max(-INF, d[e[j].a] + e[j].cost);
          p[e[j].b] = e[j].a;
          x = e[j].b;
        }
  }

  if (x == -1)
    cout << "No negative cycle from " << v;
  else {
    int y = x;
    for (int i = 0; i < n; ++i) y = p[y];

    vector<int> path;
    for (int cur = y;; cur = p[cur]) {
      path.push_back(cur);
      if (cur == y && path.size() > 1) break;
    }
    reverse(path.begin(), path.end());

    cout << "Negative cycle: ";
    for (size_t i = 0; i < path.size(); ++i) cout << path[i] << ' ';
  }
}

// spfa
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;

bool spfa(int s, vector<int>& d) {
  int n = adj.size();
  d.assign(n, INF);
  vector<int> cnt(n, 0);
  vector<bool> inqueue(n, false);
  queue<int> q;

  d[s] = 0;
  q.push(s);
  inqueue[s] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    inqueue[v] = false;

    for (auto edge : adj[v]) {
      int to = edge.first;
      int len = edge.second;

      if (d[v] + len < d[to]) {
        d[to] = d[v] + len;
        if (!inqueue[to]) {
          q.push(to);
          inqueue[to] = true;
          cnt[to]++;
          if (cnt[to] > n) return false;  // negative cycle
        }
      }
    }
  }
  return true;
}