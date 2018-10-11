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

const int inf = 1e9;
int x;
int a[11][103];
int dp[10][103];

int travl(int att, int start) {
  if(att < 0 || att > 9) return inf;
  if(start == x) {
    if(att == 0) return 0;
    else return inf;
  }
  if(dp[att][start] != inf) return dp[att][start];
  int val = inf;
  val = min(val, travl(att-1, start+1) + 20);
  val = min(val, travl(att, start+1) + 30);
  val = min(val, travl(att+1, start+1) + 60);
  val -= a[att][start];
  dp[att][start] = val;
  return val;
}
int main() {
  int n;
  scanf("%d", &n);
  while(n--) {
    scanf("%d", &x);
    x/=100;
    for(int i=9; i>=0; i--) {
      for(int j=0; j<x; j++) {
        scanf("%d", &a[i][j]);
      }
    }
    for(int i=0; i<10; i++) for(int j=0; j<x; j++) dp[i][j] = inf;
    printf("%d\n", travl(0, 0));
    printf("\n");
  }
}
