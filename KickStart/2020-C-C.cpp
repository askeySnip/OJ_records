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
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n;
int a[100010], c[2 * 100 * 100010 + 1];

void solve() {
  int s1 = 0, s2 = 0;
  REP(i, 0, n) if (a[i] < 0) s1 -= a[i];
  else s2 += a[i];
  int t = 0;
  ll ans = 0;
  ++c[s1];
  REP(i, 0, n) {
    t += a[i];
    for (int j = 0; j * j <= s2; j++) {
      if (s1 + (t - j * j) >= 0) ans += c[s1 + (t - j * j)];
    }
    ++c[s1 + t];
  }
  printf("%lld\n", ans);
  memset(c, 0, 4 * (s1 + s2 + 1));
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
