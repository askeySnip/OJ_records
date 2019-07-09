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
#include <climits>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
int n;
char line[256];
ll dp[256][256];

ll decode(int l, int r) {
  ll ret = 0;
  REP(i, l, r+1) {
    ret *= 10;
    ret += (line[i] - '0');
  }
  return ret;
}

ll dfs(int l, int r) {
  if(l == r) return (ll)(line[l] - '0');
  if(l > r) return 0;
  if(dp[l][r]) return dp[l][r];
  ll& ret = dp[l][r];
  REP(i, l, r+1) {
    ll v = decode(l, i);
    if(v > INT_MAX) break;
    ret = max(ret, v + dfs(i+1, r));
  }
  return ret;
}

int main() {
  scanf("%d", &n);
  REP(i, 0, n) {
    scanf("%s", line);
    int len = strlen(line);
    memset(dp, 0, sizeof dp);
    printf("%lld\n", dfs(0, len - 1));
  }
  return 0;
}
