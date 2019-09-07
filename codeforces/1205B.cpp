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
int n;
ll a[100024];
int cnt[64];
vii e;

int sp(int id) {
  int s = e[id].first, t = e[id].second;
  map<int, int> dist;
  deque<int> dq;
  dist[s] = 0;
  REP(i, 0, e.size()) {
    if(i == id) continue;
    if(e[i].first == s && dist.find(e[i].second) == dist.end()) dq.push_back(e[i].second), dist[e[i].second] = 1;
    if(e[i].second == s && dist.find(e[i].first) == dist.end()) dq.push_back(e[i].first), dist[e[i].first] = 1;
  }
  while(!dq.empty()) {
    int u = dq.front(); dq.pop_front();
    REP(i, 0, e.size()) {
      if(e[i].first == u && dist.find(e[i].second) == dist.end()) {
        dist[e[i].second] = dist[e[i].first]+1;
        dq.push_back(e[i].second);
        if(e[i].second == t) return dist[t];
      }
      if(e[i].second == u && dist.find(e[i].first) == dist.end()) {
        dist[e[i].first] = dist[e[i].second]+1;
        if(e[i].first == t) return dist[t];
        dq.push_back(e[i].first);
      }
    }
  }
  return inf;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  REP(i, 0, n) cin >> a[i];
  REP(i, 0, n) {
    REP(j, 0, 64) {
      if(a[i] & ((ll)1 << j)) cnt[j]++;
    }
  }
  REP(i, 0, 64) {
    if(cnt[i] >= 3) {
      cout << 3 << endl;
      return 0;
    }
  }
  memset(cnt, 0, sizeof cnt);
  REP(i, 0, n) {
    REP(j, 0, 64) {
      if(a[i] & ((ll)1 << j)) {
        if(cnt[j]) {
          e.push_back(ii(cnt[j], i+1));
        } else {
          cnt[j] = i+1;
        }
      }
    }
  }
  vii te;
  sort(e.begin(), e.end());
  REP(i, 0, e.size()) {
    if(te.empty() || e[i]!=te.back()) te.push_back(e[i]);
  }
  e = te;
  int ans = inf;
  REP(i, 0, e.size()) {
    int d = sp(i);
    ans = min(d, ans);
  }
  if(ans == inf) cout << -1 << endl;
  else cout << ans + 1 << endl;
  return 0;
}
