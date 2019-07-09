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
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
char in[100];
int dp[100][100];

int dfs(int l, int r) {
  if(l == r) return 1;
  if(dp[l][r]) return dp[l][r];
  int& ret = dp[l][r];
  ret = 0xfffffff;
  REP(i, l, r) {
    ret = min(ret, dfs(l, i) + dfs(i+1, r));
  }
  int sublen = r - l + 1;
  REP(i, 1, sublen) {
    if(sublen % i == 0) {
      int j = 0, k = l;
      for(; k<=r; k++) {
        if(in[k] != in[l+j]) break;
        j++;
        if(j >= i) j = 0;
      }
      if(k == r+1) {
        ret = min(ret, dfs(l, l+i-1));
      }
    }
  }
  return ret;
}

int main() {
  while(scanf("%s", in), in[0] != '*') {
    memset(dp, 0, sizeof dp);
    int len = strlen(in);
    printf("%d\n", dfs(0, len-1));
  }
  return 0;
}
