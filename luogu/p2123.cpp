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
const int inf = 1e9;
const int mod = 1e9 + 7;

// struct
struct node {
  ll l, r, d;
};

// data
int n;
node a[20024];

void solve() {
  sort(a, a + n, [](node x, node y) {
    if (x.d != y.d) return x.d < y.d;
    if (x.d <= 0) return x.l < y.l;
    return x.r > y.r;
  });
  ll ans = 0;
  ll presum = 0;
  REP(i, 0, n) {
    presum += a[i].l;
    ans = max(ans, presum) + a[i].r;
  }
  printf("%lld\n", ans);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) {
      scanf("%lld%lld", &a[i].l, &a[i].r);
      if (a[i].l > a[i].r)
        a[i].d = 1;
      else if (a[i].l < a[i].r)
        a[i].d = -1;
      else
        a[i].d = 0;
    }
    solve();
  }
  return 0;
}
