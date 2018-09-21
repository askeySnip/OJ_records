
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
const int MOD = 1000000;
int n, k;
int mem[103][103];
int dfs(int n, int k) {
  if(k == 1) return 1;
  if(mem[n][k]) return mem[n][k];
  int c = 0;
  for(int i=0; i<=n; i++) {
    c = (dfs(n-i, k-1)%MOD + c%MOD)%MOD;
  }
  return mem[n][k] = c;
}
int main() {
  while(scanf("%d %d", &n, &k), n || k){
    memset(mem, 0, sizeof mem);
    printf("%d\n", dfs(n, k));
  }
}
