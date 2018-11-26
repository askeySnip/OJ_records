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
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9

// data
int n, k;
int a[666];
int dp[333][666];

int main() {
  while(scanf("%d %d", &n, &k) == 2) {
    a[0] = 0;
    for(int i=1; i<=n+1; i++) {
      scanf("%d", &a[i]);
      a[i] += a[i-1];
    }
    memset(dp, 0, sizeof dp);
    for(int j=1; j<=n+1; j++) {
      dp[1][j] = a[j];
    }
    for(int i=2; i<=k+1; i++) {
      for(int j=1; j<=n+1; j++) {
        if(i > j) continue;
        int t = inf;
        for(int jj=j-1; jj>=i-1; jj--) {
          t = min(t, max(dp[i-1][jj], a[j] - a[jj]));
        }
        dp[i][j] = t;
      }
    }

    printf("%d\n", dp[k+1][n+1]);
  }
  return 0;
}
