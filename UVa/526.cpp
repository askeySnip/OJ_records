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
int dp[200][200];
char a[200], b[200];
int c = 1, ins = 0, del = 0;

void printOp(int lena, int lenb) {
  if(lena <= 0 && lenb <= 0) return;
  if(lena <= 0) {
    printOp(lena, lenb-1);
    printf("%d Insert %d,%c\n", c++, lena+1+ins-del, b[lenb]);
    ins++;
    return;
  }
  if(lenb <= 0) {
    printOp(lena-1, lenb);
    printf("%d Delete %d\n", c++, lena + ins - del);
    del++;
    return;
  }
  if(a[lena] == b[lenb]) printOp(lena-1, lenb-1);
  else if(dp[lena][lenb] == dp[lena-1][lenb-1]+1) {
    printOp(lena-1, lenb-1);
    printf("%d Replace %d,%c\n", c++, lena + ins - del, b[lenb]);
  } else if(dp[lena][lenb] == dp[lena-1][lenb]+1) {
    printOp(lena-1, lenb);
    printf("%d Delete %d\n", c++, lena + ins - del);
    del++;
  } else {
    printOp(lena, lenb-1);
    printf("%d Insert %d,%c\n", c++, lena + 1 + ins - del, b[lenb]);
    ins++;
  }
}

int main() {
  int kase = 0;
  while(gets(a+1)) {
    if(kase++) printf("\n");
    gets(b+1);
    c = 1; ins = 0, del = 0;
    int lena = strlen(a+1), lenb = strlen(b+1);
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    REP(i, 1, lena+1) dp[i][0] = dp[i-1][0]+1;
    REP(i, 1, lenb+1) dp[0][i] = dp[0][i-1]+1;
    for(int i=1; i<=lena; i++) {
      for(int j=1; j<=lenb; j++) {
        if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1];
        else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
      }
    }
    printf("%d\n", dp[lena][lenb]);
    printOp(lena, lenb);
  }
  return 0;
}
