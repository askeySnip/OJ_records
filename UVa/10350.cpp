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
char name[100];
int n, m;
int dp[2][20];

int main() {
  while(scanf("%s", name) == 1) {
    memset(dp, 0, sizeof dp);
    scanf("%d %d", &n, &m);
    int v, last;
    for(int i=0; i<n-1; i++) {
      last = i%2;
      for(int k=0; k<m; k++) {
        scanf("%d", &v);
        dp[1 - last][k] = dp[last][0] + v;
      }
      for(int j=1; j<m; j++) {
        for(int k=0; k<m; k++) {
          scanf("%d", &v);
          dp[1-last][k] = min(dp[1-last][k], dp[last][j] + v);
        }
      }
    }
    int ans = inf;
    for(int i=0; i<m; i++) {
      ans = min(ans, dp[1-last][i]);
    }
    printf("%s\n%d\n", name, ans + 2 * (n-1));
  }
  return 0;
}
