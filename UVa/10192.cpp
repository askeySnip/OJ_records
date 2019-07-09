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
char a[200], b[200];
int dp[200][200];
int main() {
  int kase = 0;
  while(gets(a+1), a[1] != '#') {
    gets(b+1);
    memset(dp, 0, sizeof dp);
    int lena = strlen(a+1), lenb = strlen(b+1);
    REP(i, 1, lena+1) {
      REP(j, 1, lenb+1) {
        if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
        else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
    printf("Case #%d: you can visit at most %d cities.\n", ++kase, dp[lena][lenb]);
  }
  return 0;
}
