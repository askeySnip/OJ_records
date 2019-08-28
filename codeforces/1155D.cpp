/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
// int n, x;
// ll a[300024];
// const ll linf = 1e18;
// ll dp[300024][3][3];

// int main() {
//   ios::sync_with_stdio(false);
//   cin.tie(0);

//   cin >> n >> x;
//   REP(i, 0, n) cin >> a[i];
//   REP(i, 0, n) {
//     REP(j, 0, 3) {
//       REP(k, 0, 3) {
//         dp[i][j][k] = -linf;
//       }
//     }
//   }
//   dp[0][0][0] = 0;
//   REP(i, 0, n+1) {
//     REP(j, 0, 3) {
//       REP(k, 0, 3) {
//         if(k < 2) dp[i][j][k+1] = max(dp[i][j][k+1], dp[i][j][k]);
//         if(j < 2) dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
//         if(i < n) dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * ll(k == 1 ? x : 1));
//       }
//     }
//   }
//   cout << dp[n][2][2] << endl;
//   return 0;
// }
int n, x, a[300024];
ll dp[300024][3], ans;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  scanf("%d %d", &n, &x);
  for(int i=1; i<=n; i++){
    scanf("%d", &a[i]);
    dp[i][0] = max(dp[i-1][0], 0ll) + a[i];
    dp[i][1] = max(max(dp[i-1][1], dp[i-1][0]), 0ll) + 1ll * a[i] * x;
    dp[i][2] = max(max(max(dp[i-1][1], dp[i-1][0]), dp[i-1][2]), 0ll) + a[i];
    ans = max(ans, max(max(dp[i][0], dp[i][1]), dp[i][2]));
  }
  cout << ans << endl;
  return 0;
}
