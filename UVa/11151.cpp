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
int dp[1024][1024];
char s[1024];

int dfs(int l, int r) {
  if(l > r) return 0;
  if(l == r) return 1;
  if(dp[l][r]) return dp[l][r];
  int& ret = dp[l][r];
  if(s[l] == s[r]) ret = dfs(l+1, r-1) + 2;
  else {
    for(int i = r; i>l; i--) {
      if(s[l] == s[i]) {
        ret = max(ret, dfs(l+1, i-1) + 2);
        break;
      }
    }
    for(int i=l; i<r; i++) {
      if(s[i] == s[r]) {
        ret = max(ret, dfs(i+1, r-1) + 2);
        break;
      }
    }
    ret = max(ret, max(dfs(l+1, r), dfs(l, r-1)));
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  getchar();
  REP(i, 0, t) {
    gets(s);
    memset(dp, 0, sizeof dp);
    int len = strlen(s);
    printf("%d\n", dfs(0, len-1));
  }
  return 0;
}
