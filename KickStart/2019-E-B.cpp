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
typedef vector<double> vi;
typedef pair<double, double> ii;
typedef vector<pair<double, double> > vii;
typedef long long ll;
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

class UnionFind {
 private:
  vi p, rank;

 public:
  UnionFind(int n) {
    p.assign(n, 0);
    rank.assign(n, 0);
    REP(i, 0, n) p[i] = i;
  }
  int findSet(int i) { return (i == p[i] ? i : (p[i] = findSet(p[i]))); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      int x = findSet(i), y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
      } else {
        p[x] = y;
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

int d, s;
vii ce;
vii ab;
vector<double> sumc, sume;

bool cmp(ii& a, ii& b) { return a.first / a.second > b.first / b.second; }

bool check(int u) {
  if (sumc[s] < ab[u].first) return false;
  int indx = upper_bound(sumc.begin(), sumc.end(), ab[u].first) - sumc.begin();
  if (indx == s + 1) {
    if (ab[u].second) return false;
    return true;
  }
  double f = (sumc[indx] - ab[u].first) / ce[indx - 1].first;
  int eatindx = lower_bound(sume.begin(), sume.end(),
                            ab[u].second - f * ce[indx - 1].second) -
                sume.begin();
  if (eatindx + indx > s) return false;
  return true;
}

string solve() {
  string ans;
  sort(ce.begin(), ce.end(), cmp);
  sumc.resize(s + 1);
  sume.resize(s + 1);
  sumc[0] = 0;
  sume[0] = 0;
  for (int i = 0; i < s; i++) {
    sumc[i + 1] = ce[i].first + sumc[i];
    sume[i + 1] = ce[s - 1 - i].second + sume[i];
  }
  REP(i, 0, d) {
    if (check(i))
      ans = ans + "Y";
    else
      ans = ans + "N";
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    ce.clear();
    ab.clear();
    scanf("%d%d", &d, &s);
    double c, e, a, b;
    REP(i, 0, s) {
      scanf("%lf%lf", &c, &e);
      ce.push_back({c, e});
    }
    REP(i, 0, d) {
      scanf("%lf%lf", &a, &b);
      ab.push_back({a, b});
    }
    printf("Case #%d: %s\n", ++kase, solve().c_str());
  }
  return 0;
}
