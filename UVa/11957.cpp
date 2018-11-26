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
const int mod = 1000007;

// data
int n;
char graph[103][103];
ll dp[103][103];

void leftup(int i, int j) {
  if(j && i) {
    if(graph[i-1][j-1] != 'B') {
      dp[i-1][j-1] += dp[i][j];
      dp[i-1][j-1] %= mod;
    }else {
      if(j>1 && i>1) {
        dp[i-2][j-2] += dp[i][j];
        dp[i-2][j-2] %= mod;
      }
    }
  }
}

void rightup(int i, int j) {
  if(j!=n-1 && i) {
    if(graph[i-1][j+1] != 'B') {
      dp[i-1][j+1] += dp[i][j];
      dp[i-1][j+1] %= mod;
    }else {
      if(j<n-1 && i>1) {
        dp[i-2][j+2] += dp[i][j];
        dp[i-2][j+2] %= mod;
      }
    }
  }
}
int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
      scanf("%s", graph[i]);
    }
    memset(dp, 0, sizeof dp);
    for(int i=n-1; i>=0; i--) {
      for(int j=0; j<n; j++) {
        if(graph[i][j] == '.') {
          leftup(i, j);
          rightup(i, j);
        }else if(graph[i][j] == 'B') {
          dp[i][j] = 0;
        }else {
          dp[i][j] = 1;
          leftup(i, j);
          rightup(i, j);
        }
      }
    }

    ll ans = 0;
    for(int i=0; i<n; i++) {
      ans += dp[0][i];
      ans %= mod;
    }
    printf("Case %d: %lld\n", ++kase, ans);
  }
  return 0;
}
