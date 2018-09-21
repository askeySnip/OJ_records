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
int l, n;
int c[52];
int mem[1024][1024];
//int mid[1024][1024];
int dp(int left, int right) {
  if(left+1 == right) return 0;
  if(mem[left][right]) return mem[left][right];
  int ret = 99999999;
  for(int i=left+1; i<right; i++) {
    ret = min(ret, dp(left, i)+dp(i, right)+c[right]-c[left]);
  }
  return mem[left][right] = ret;
}
int main() {
  while(scanf("%d", &l), l) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    c[0] = 0; c[n+1] = l;
    // dp(n, 0L);
    memset(mem, 0, sizeof mem);
    //  memset(mid, 0, sizeof mid);
    printf("The minimum cutting is %d.\n", dp(0, n+1));
  }
}
