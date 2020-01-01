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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, m;
ii a[200010];
int k[200010], pos[200010];
int ans[200010];

bool cmp(ii& a, ii& b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

void solve() {
  sort(a, a + n, cmp);
  vector<pair<ii, int>> v;
  REP(i, 0, m) v.push_back(mp(ii(k[i], pos[i]), i));
  sort(v.begin(), v.end());
  set<ii> s;
  int pt = n - 1;
  REP(i, 0, m) {
    int tk = v[i].first.first, tpos = v[i].first.second;
    int id = v[i].second;
    while (s.size() < tk) {
      s.insert(ii(a[pt].second, a[pt].first));
      pt--;
    }
    auto it = s.begin();
    advance(it, tpos - 1);
    ans[id] = it->second;
  }
  REP(i, 0, m) { printf("%d\n", ans[i]); }
}

int main() {
  int kase = 0;
  // scanf("%d", &kase);
  kase = 1;
  while (kase--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i].first), a[i].second = i;
    scanf("%d", &m);
    REP(i, 0, m) scanf("%d%d", &k[i], &pos[i]);
    solve();
  }

  return 0;
}
