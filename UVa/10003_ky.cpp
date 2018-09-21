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
int mid[1024][1024];
int main() {
  while(scanf("%d", &l), l) {
    scanf("%d", &n);
    for(int i=1; i<=n; i++) scanf("%d", &c[i]);
    c[0] = 0; c[n+1] = l;
    // dp(n, 0L);
    // memset(mem, 0, sizeof mem);
    // memset(mid, 0, sizeof mid);
    for(int s = 0; s<=n+1; s++) {
      for(int left = 0; left+s<=n+1; left++) {
        int r = left+s;
        if(s < 2) {
          mem[left][r] = 0;
          mid[left][r] = left;
          continue;
        }
        int mleft = mid[left][r-1];
        int mright = mid[left+1][r];
        mem[left][r] = 10000000;
        for(int m = mleft; m<=mright; m++) {
          int tres = mem[left][m] + mem[m][r] + (c[r]-c[left]);
          if(tres < mem[left][r]) {
            mem[left][r] = tres;
            mid[left][r] = m;
          }
        }
      }
    }
    printf("The minimum cutting is %d.\n", mem[0][n+1]);
  }
}
