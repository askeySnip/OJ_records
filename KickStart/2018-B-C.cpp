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

int n, v, h, A, B, C, D, E, F, M;
map<int, set<int> > maps;

class BIT {
 private:
  vi ft;

 public:
  BIT(int n) { ft.assign(n + 1, 0); }
  void add(int k) {
    k += 1;
    for (; k < ft.size(); k += (k & (-k))) {
      ft[k - 1]++;
    }
  }
  int sum(int k) {
    int ret = 0;
    k += 1;
    for (; k > 0; k -= (k & (-k))) ret += ft[k - 1];
    return ret;
  }
  void del(int k) {
    k += 1;
    for (; k < ft.size(); k += (k & (-k))) ft[k - 1]--;
  }
};

ll solve() {
  maps.clear();
  maps[v].insert(h);
  BIT total(M);
  total.add(h);
  for (int i = 1; i < n; i++) {
    int x = (1LL * A * v + 1LL * B * h + C) % M;
    int y = (1LL * D * v + 1LL * E * h + F) % M;
    v = x, h = y;
    // cout << v << " " << h << endl;
    maps[v].insert(h);
    total.add(h);
  }
  ll to_minus = 0;
  BIT lower(M);
  int l = 0, h = n;
  for (auto i = maps.begin(); i != maps.end(); i++) {
    for (auto& y : i->second) {
      total.del(y);
    }
    h -= i->second.size();
    for (auto& y : i->second) {
      ll llo, lhi, rlo, rhi;
      llo = y > 0 ? lower.sum(y - 1) : 0;
      lhi = l - lower.sum(y);
      rlo = y > 0 ? total.sum(y - 1) : 0;
      rhi = h - total.sum(y);
      to_minus += llo * rhi + lhi * rlo;
    }
    for (auto& y : i->second) {
      lower.add(y);
    }
    l += i->second.size();
  }
  ll ans = 1LL * n * (n - 1) * (n - 2) / 6 - to_minus;
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int a, b, c;
  while (t--) {
    scanf("%d%d%d%d%d%d%d%d%d%d", &n, &v, &h, &A, &B, &C, &D, &E, &F, &M);
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
