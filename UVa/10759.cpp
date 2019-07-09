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
typedef unsigned long long ull;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
ull dp[30][150];
int n, x;

ull gcd(ull a, ull b) {
  if(b == 0) return a;
  else return gcd(b, a%b);
}

int main() {
  while(scanf("%d %d", &n, &x), n || x) {
    memset(dp, 0, sizeof dp);
    REP(i, 1, 7) dp[1][i] = 1;
    REP(i, 1, n) {
      REP(j, 0, 150) {
        if(dp[i][j] == 0) continue;
        REP(k, 1, 7) {
          dp[i+1][j+k] += dp[i][j];
        }
      }
    }
    ull a = 0, b = 0;
    REP(i, n, 150) {
      if(i >= x) a += dp[n][i];
      b += dp[n][i];
    }
    if(a == 0) printf("0\n");
    else if(a == b) printf("1\n");
    else {
      ull d = gcd(b, a);
      printf("%lld/%lld\n", a/d, b/d);
    }
  }
  return 0;
}
