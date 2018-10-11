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

int n, x, t, k;
double val[103];
int p[103];
double dp[26][103][2300];

double solve(int dishs, int id, int m) {
  if(dishs > 2*(n+1)) return -10000000;
  int trail = ceil((t*(n+1)+m)*1.1);
  if(x*(n+1) < trail) return -10000000;
  if(id == k || dishs == 2*(n+1) || x*(n+1) == trail) return 0;
  if(dp[dishs][id][m] != -1) return dp[dishs][id][m];
  //  cout << dishs << " " << id << " " << m << endl;
  dp[dishs][id][m] = max(solve(dishs, id+1, m), solve(dishs+1, id+1, m+p[id])+val[id]);
  dp[dishs][id][m] = max(dp[dishs][id][m], solve(dishs+2, id+1, m+p[id]*2)+2*val[id]);
  //  cout << dishs << " " << id << " " << m << " " << dp[dishs][id][m] << endl;
  return dp[dishs][id][m];
}


int main() {

  while(scanf("%d %d %d %d", &n, &x, &t, &k), n||x||t||k) {
    for(int i=0; i<k; i++) {
      scanf("%d", &p[i]);
      double sum = 0.0;
      int v;
      for(int i=0; i<=n; i++) {
        scanf("%d", &v);
        sum+=v;
      }
      val[i] = sum*1.0/(n+1);
    }

    //  memset(dp, -1, sizeof dp);
    for(int i=0; i<26; i++) for(int j=0; j<103; j++) for(int k=0; k<2300; k++) dp[i][j][k] = -1;
    printf("%.2lf\n", solve(0,0,0));
  }
  return 0;
}
