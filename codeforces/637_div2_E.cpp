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
int n, m, g, r;
vi d;
vector<vi> dist, vist;

void solve() {
  ll ans = -1;
  deque<ii> dq;
  dq.push_back({0, 0});
  vist[0][0] = 1;
  while (!dq.empty()) {
    int v = dq.front().first, t = dq.front().second;
    dq.pop_front();
    if (t == 0) {
      int tTo = n - d[v];
      if (tTo <= g) {
        ll tmp = 1LL * (g + r) * dist[v][t] + tTo;
        if (ans == -1 || ans > tmp) ans = tmp;
      }
    }
    if (t == g) {
      if (!vist[v][0]) {
        dist[v][0] = dist[v][g] + 1;
        vist[v][0] = 1;
        dq.push_back({v, 0});
      }
      continue;
    }
    if(v) {
      int tTo = d[v] - d[v-1] + t;
      if(tTo <= g && !vist[v-1][tTo]) {
        vist[v-1][tTo] = 1;
        dq.push_front({v-1, tTo});
        dist[v-1][tTo] = dist[v][t];
      }
    }
    if(v < m-1) {
      int tTo = d[v+1] - d[v] + t;
      if(tTo <= g && !vist[v+1][tTo]) {
        vist[v+1][tTo] = 1;
        dq.push_front({v+1, tTo});
        dist[v+1][tTo] = dist[v][t];
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  d.resize(m + 2);
  REP(i, 0, m) cin >> d[i + 1];
  d[m + 1] = n;
  sort(d.begin(), d.end());
  m += 2;
  cin >> g >> r;
  dist.assign(m, vi(g + 1, 0));
  vist.assign(m, vi(g + 1, 0));
  solve();
  return 0;
}
