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

int n, k;
int a[5100];

int solve() {
  sort(a, a + n);
  int pos = 0, day = 1;
  int ans = 0;
  while (true) {
    int it = lower_bound(a + pos, a + n, day) - a;
    ans += min(k, n - it);
    pos = it + k;
    if (pos >= n) break;
    day++;
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
