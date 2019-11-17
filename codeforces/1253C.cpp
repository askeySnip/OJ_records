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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, m;
int a[200010];
ll sum[200010];
ll ans[200010];

void solve() {
  sort(a + 1, a + n + 1);
  ans[0] = 0;
  REP(i, 1, n + 1) {
    ans[i] = ans[i - 1];
    sum[i % m] += a[i];
    ans[i] += sum[i % m];
  }
  REP(i, 1, n + 1) {
    if (i > 1) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d%d", &n, &m);
    REP(i, 1, n + 1) scanf("%d", &a[i]);
    solve();
  }
  return 0;
}
