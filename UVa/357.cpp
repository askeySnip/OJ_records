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
int main() {
  int n;
  long long dp[30024];
  int a[5] = {50, 25, 10, 5, 1};
  while(scanf("%d", &n) != EOF) {
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for(int i=0; i<5; i++) {
      for(int j=a[i]; j<=n; j++) {
        dp[j] += dp[j-a[i]];
      }
    }
    if(dp[n] > 1) printf("There are %lld ways to produce %d cents change.\n", dp[n], n);
    else printf("There is only 1 way to produce %d cents change.\n", n);
  }
  return 0;
}
