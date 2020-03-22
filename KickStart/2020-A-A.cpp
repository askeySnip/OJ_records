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

int n, b;
int a[100010];

void solve() {
  sort(a + 1, a + n + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (b >= a[i]) {
      b -= a[i];
      ans++;
    } else
      break;
  }
  printf("%d\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &b);
    REP(i, 1, n + 1) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
