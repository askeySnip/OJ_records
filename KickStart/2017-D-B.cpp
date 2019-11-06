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

// struct
#define inf 1e15
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// data
int n, k, a1, b1, c, d, e1, e2, f;
int x[100010], y[100010], r[100010], s[100010];
int a[100010], b[100010];

int solve() {
  x[1] = a1, y[1] = b1, r[1] = 0, s[1] = 0;
  REP(i, 2, n + 1) {
    x[i] = (c * x[i - 1] + d * y[i - 1] + e1) % f;
    y[i] = (d * x[i - 1] + c * y[i - 1] + e2) % f;
    r[i] = (c * r[i - 1] + d * s[i - 1] + e1) % 2;
    s[i] = (d * r[i - 1] + c * s[i - 1] + e2) % 2;
    a[i] = r[i] == 0 ? x[i] : -x[i];
    b[i] = s[i] == 0 ? y[i] : -y[i];
  }
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d%d%d%d%d%d", &n, &k, &a1, &b1, &c, &d, &e1, &e2, &f);
    printf("Case #%d: %d\n", ++kase, solve());
  }

  return 0;
}
