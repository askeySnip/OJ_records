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

int m, n;
int p[103], f[103];
int dp[103][12024];

int solve(int w, int id) {
  if(w > m && m < 1800) return -1000;
  if(w > m + 200) return -1000;
  if(id == n) {
    if(w > m && w <= 2000) return -1000;
    return 0;
  }
  if(dp[id][w]) return dp[id][w];
  return dp[id][w] = max(solve(w, id+1), solve(w + p[id], id+1) + f[id]);
}

int main() {

  while(scanf("%d %d", &m, &n) != EOF) {
    for(int i=0; i<n; i++) {
      scanf("%d %d", &p[i], &f[i]);
    }
    memset(dp, 0, sizeof dp);
    printf("%d\n", solve(0, 0));
  }
}
