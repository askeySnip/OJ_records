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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int w, h, l, u, r, d;
double log_x[1000100];

double choose(int a, int b) {
  if (b < 0 || b > a) return 0;
  return pow(2, log_x[a] - log_x[b] - log_x[a - b] - a);
}

void solve() {
  double ans = 0;
  --w, --h, --l, --u, --r, --d;
  int lx = r, ly = u;
  if (r < w) {
    double multi = 1.0;
    while (ly > 0) {
      --ly;
      ++lx;
      if (lx >= w) {
        lx = w - 1;
        multi = 0.5;
      }
      ans += multi * choose(lx + ly, lx);
    }
  }
  swap(w, h);
  swap(l, u);
  swap(r, d);
  lx = r, ly = u;
  if (r < w) {
    double multi = 1.0;
    while (ly > 0) {
      --ly;
      ++lx;
      if (lx >= w) {
        lx = w - 1;
        multi = 0.5;
      }
      ans += multi * choose(lx + ly, lx);
    }
  }
  printf("%.10f\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    log_x[0] = 0;
    for (int i = 1; i < 1000010; i++) {
      log_x[i] = log2(i) + log_x[i - 1];
    }
    scanf("%d%d%d%d%d%d", &w, &h, &l, &u, &r, &d);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
