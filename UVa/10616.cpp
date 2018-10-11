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

ll n, q, d, m;
ll a[256];
ll dp[16][256][24];             // dp[i][j][k] means choose i nums from range(0, j) with remainder k;

ll solve() {
  dp[0][0][0] = 1;
  for(int i=1; i<=m; i++) {
    for(int j=i; j<=n; j++) {
      for(int k=0; k<d; k++) {
        for(int l=0; l<j; l++) {
          dp[i][j][k] += dp[i-1][l][(k+d-a[j]%d)%d];
        }
      }
    }
  }
  // for(int i=1; i<=m; i++) {
  //   for(int j=1; j<=n; j++) {
  //     for(int k=0; k<d; k++) {
  //       cout << dp[i][j][k] << " ";
  //     }
  //     cout << endl;
  //   }
  //   cout << endl << endl;
  // }
  int ret = 0;
  for(int i=1; i<=n; i++) ret += dp[m][i][0];
  return ret;
}

// A better solvetion for this problem.

// void solve(int N, int M, int D) {
// 	memset(DP, 0, sizeof(DP));
// 	int i, j, k;
// 	long long tmp;
// 	DP[0][0][0] = 1;
// 	for(i = 1; i <= N; i++) {
// 		for(j = 0; j <= M; j++) {
// 			for(k = 0; k < D; k++) {
// 				tmp = (k+A[i])%D;
// 				if(tmp < 0) tmp += D;
// 				DP[i][j][k] += DP[i-1][j][k];
// 				if(j) {
// 					DP[i][j][k] += DP[i-1][j-1][tmp];
// 				}
// 			}
// 		}
// 	}
// 	printf("%lld\n", DP[N][M][0]);
// }


int main() {

  int kase = 0;
  while(scanf("%lld %lld", &n, &q), n||q) {
    for(int i=1; i<=n; i++) scanf("%lld", &a[i]);
    printf("SET %d:\n", ++kase);
    int qkase = 0;
    for(int i=0; i<q; i++) {
      scanf("%lld %lld", &d, &m);
      memset(dp, 0, sizeof dp);
      printf("QUERY %d: %lld\n", ++qkase, solve());
    }
  }
  return 0;
}
