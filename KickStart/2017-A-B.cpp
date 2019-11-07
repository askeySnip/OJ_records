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
const int mod = 1e9 + 7;

// data
char a[10000], b[10000], tmp[10000];
bool dp[10000][10000];
int lena, lenb;

void solve() {
  for(int i=0; i<=lena; i++) {
    for(int j=0; j<=lenb; j++) {
      dp[i][j] = 0;
    }
  }
  dp[0][0] = 1;
  for(int i=0; i<=lena; i++) {
    for(int j=0; j<=lenb; j++) {
      if(dp[i][j]) {
        dp[i+1][j] |= !a[i+1];
        dp[i][j+1] |= !b[j+1];
        dp[i+1][j+1] |= (!a[i+1] || !b[j+1] || a[i+1] == b[j+1]);
      }
    }
  }
  if(dp[lena][lenb]) printf("TRUE\n");
  else printf("FALSE\n");
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while(t--) {
    scanf("%s", tmp);
    int l = strlen(tmp);
    lena = 0;
    REP(i, 0, l) {
      if(tmp[i] == '*') {
        REP(j, 0, 4) a[++lena] = 0;
      } else {
        a[++lena] = tmp[i];
      }
    }
    scanf("%s", tmp);
    l = strlen(tmp);
    lenb = 0;
    REP(i, 0, l) {
      if(tmp[i] == '*') {
        REP(j, 0, 4) b[++lenb] = 0;
      } else {
        b[++lenb] = tmp[i];
      }
    }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
