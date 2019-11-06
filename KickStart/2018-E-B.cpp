/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

struct node {
  int dif;
  string s;
  node(int d, string st) : dif(d), s(st) {}
  bool operator<(const node& b) const { return dif < b.dif; }
};

int n, m, p;
string pref[110];
map<string, int> ump;
int dif[2][110];

int solve() {
  memset(dif, 0, sizeof dif);
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < n; j++) {
      if (pref[j][i] == '1')
        dif[0][i]++;
      else
        dif[1][i]++;
    }
  }
  priority_queue<node> pq;
  vector<node> vn;
  pq.push(node(dif[0][0], "0"));
  pq.push(node(dif[1][0], "1"));
  for (int i = 1; i < p; i++) {
    while (!pq.empty()) {
      node nd = pq.top();
      pq.pop();
      vn.push_back(node(nd.dif + dif[0][i], nd.s + "0"));
      vn.push_back(node(nd.dif + dif[1][i], nd.s + "1"));
    }
    while (!vn.empty()) {
      pq.push(vn.back());
      // cout << i << " " << vn.back().dif << " " << vn.back().s << endl;
      vn.pop_back();
      if (pq.size() > 101) pq.pop();
    }
  }
  int ans = inf;
  while (!pq.empty()) {
    node nd = pq.top();
    pq.pop();
    if (ump.find(nd.s) == ump.end()) ans = min(ans, nd.dif);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t, kase = 0;
  // scanf("%d", &t);
  cin >> t;
  string f;
  while (t--) {
    // scanf("%d%d%d", &n, &m, &p);
    ump.clear();
    cin >> n >> m >> p;
    REP(i, 0, n) cin >> pref[i];
    REP(i, 0, m) {
      cin >> f;
      ump[f]++;
    }
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
