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
char line[100];
ll dp[2][20];
ll ans;
int n;
inline int decode(char c) {
  if(c >= '1' && c <= '9') return c-'1';
  else return c-'A'+9;
}


int main() {
  while(scanf("%s", line) == 1) {
    ans = 0;
    n = strlen(line);
    int cur = 0;
    if(line[0] == '?') for(int i=0; i<n; i++) dp[0][i] = 1;
    else {
      memset(dp, 0, sizeof dp); dp[0][decode(line[0])] = 1;
    }
    for(int i=1; i<n; i++) {
      cur = i%2;
      ll temp = 0;
      for(int j=0; j<n; j++) {
        temp += dp[1-cur][j];
      }
      if(line[i] == '?') {
        for(int j=0; j<n; j++) {
          if(j==0) dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j+1];
          else if(j == n-1) dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j-1];
          else dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j-1] - dp[1-cur][j+1];
        }
      }else {
        int tr = decode(line[i]);
        for(int j=0; j<n; j++) {
          if(j == tr) {
            if(j==0) dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j+1];
            else if(j == n-1) dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j-1];
            else dp[cur][j] = temp - dp[1-cur][j] - dp[1-cur][j-1] - dp[1-cur][j+1];
          }else {
            dp[cur][j] = 0;
          }
        }
      }
    }
    for(int j=0; j<n; j++) {
      ans += dp[cur][j];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
