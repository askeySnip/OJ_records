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
struct food {
  int a, b, c;
};

// data
int T, n;
food f[60];

int main() {
  scanf("%d%d", &T, &n);
  REP(i, 0, n) scanf("%d", &f[i].a);
  REP(i, 0, n) scanf("%d", &f[i].b);
  REP(i, 0, n) scanf("%d", &f[i].c);
  // 选取的i，j食材的顺序影响最终的结果。所以应该先排序。
  sort(f, f + n, [](food a, food b) { return a.c * b.b < a.b * b.c; });
  ll dp[100024];
  memset(dp, 0, sizeof dp);
  ll ans = 0;
  REP(i, 0, n) {
    for (int j = T; j >= f[i].c; j--) {
      dp[j] = max(dp[j], dp[j - f[i].c] + f[i].a - 1LL * j * f[i].b);
      ans = max(ans, dp[j]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
