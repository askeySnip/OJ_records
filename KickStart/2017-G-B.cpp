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
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
const double eps = 1e-12;

// data
int n;
int r[110], b[110];
int parent[110];

int getParent(int x) {
  return (x == parent[x] ? x : parent[x] = getParent(parent[x]));
}

bool merge(int x, int y) {
  int px = getParent(x), py = getParent(y);
  if (px == py) return false;
  parent[px] = py;
  return true;
}

ll solve() {
  vector<tuple<int, int, int>> vt;
  REP(i, 0, n) {
    REP(j, i + 1, n) { vt.emplace_back(min(r[i] ^ b[j], r[j] ^ b[i]), i, j); }
  }
  sort(vt.begin(), vt.end());
  ll ans = 0;
  for (auto& e : vt) {
    int a, b, c;
    tie(a, b, c) = e;
    if (merge(b, c)) ans += a;
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &r[i]);
    REP(i, 0, n) scanf("%d", &b[i]);
    REP(i, 0, n) parent[i] = i;
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }

  return 0;
}
