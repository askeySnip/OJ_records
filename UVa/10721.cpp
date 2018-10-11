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

int n, k, m;
ll dp[52][52];

ll solve(int nn, int kk) {
  if(nn == kk) return 1L;
  if(nn > 0 && kk <= 0) return 0L;
  if(nn <= 0 && kk > 0) return 0L;
  if(kk == 1 && nn > 0 && nn <= m) return 1L;
  if(kk == 1 && nn > m) return 0;
  //  if(nn == 0 && kk == 0) return 1L;
  if(dp[nn][kk]) return dp[nn][kk];
  ll ret = 0L;
  for(int i=1; i<=m; i++) {
    ret += solve(nn-i, kk-1);
  }
  dp[nn][kk] = ret;
  return ret;
}
int main() {
  while(scanf("%d %d %d", &n, &k, &m) != EOF) {
    for(int i=0; i<52; i++) for(int j=0; j<52; j++) dp[i][j] = 0L;
    printf("%lld\n", solve(n, k));
  }
}
