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

// struct
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;
const double eps = 1e-14;

// data
int m;
int c[110];

bool bigger(double r) {
  double ans = 0;
  double t = 1;
  for (int i = m; i >= 0; i--) {
    ans += t * c[i];
    t *= (1 + r);
  }
  return ans > 0;
}

double solve() {
  double l = -1, h = 1, mid = 0;
  while (h - l > eps) {
    mid = (l + h) / 2;
    if (bigger(mid)) {
      l = mid;
    } else {
      h = mid;
    }
  }
  return l;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &m);
    REP(i, 0, m + 1) scanf("%d", &c[i]);
    c[0] = -c[0];
    printf("Case #%d: %.12f\n", ++kase, solve());
  }
  return 0;
}
