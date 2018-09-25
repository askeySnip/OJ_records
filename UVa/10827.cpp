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
int main() {
  int t, n;
  int torus[200][200];
  scanf("%d", &t);
  //memset(torus, 0, sizeof torus);
  while(t--) {
    memset(torus, 0, sizeof torus);
    scanf("%d", &n);
    int ans = -99999999;
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        scanf("%d", &torus[i][j]);
        torus[i+n][j] = torus[i][j+n] = torus[i+n][j+n] = torus[i][j];
      }
    }
    for(int i=1; i<=2*n; i++) {
      for(int j=1; j<=2*n; j++) {
        torus[i][j] += torus[i-1][j] + torus[i][j-1] - torus[i-1][j-1];
      }
    }

    for(int i=1; i<=n; i++) {
      for(int j=1; j<=n; j++) {
        for(int k=1; k<=n; k++) {
          for(int l=1; l<=n; l++) {
            int t = torus[i+k-1][j+l-1] + torus[i-1][j-1] - torus[i+k-1][j-1] - torus[i-1][j+l-1];
            if(ans < t) {
              ans = t;
            }
          }
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
