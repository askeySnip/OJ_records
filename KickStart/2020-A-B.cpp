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

int n, k, p;
int plat[60][60];
int dp[60][2000];

void solve() {
  memset(dp, 0, sizeof dp);
  for(int i=1; i<=n; i++) {
    for(int j=p; j>=0; j--) {
      for(int kk = 0; kk<=k; kk++) {
        if(j < kk) break;
        dp[i][j] = max(dp[i][j], dp[i-1][j-kk] + plat[i][kk]);
      }
    }
  }
  printf("%d\n", dp[n][p]);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d%d", &n, &k, &p);
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=k; j++) {
        scanf("%d", &plat[i][j]);
      }
      for(int j=1; j<=k; j++) {
        plat[i][j] += plat[i][j-1];
      }
    }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
