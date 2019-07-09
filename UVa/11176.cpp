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
int n;
double p;
double pos[512][512];

int main() {
  while(scanf("%d %lf", &n, &p), n) {
    REP(i, 0, n+1) {
      REP(j, 0, n+1) {
        if(i <= j) pos[i][j] = 1.0;
        else if(i == j+1) pos[i][j] = 1.0 - pow(p, i);
        else {
          pos[i][j] = pos[i-1][j] - pow(p, j+1) * (1 - p) * pos[i-j-2][j];
        }
      }
    }
    // REP(i, 0, n+1) {
    //   REP(j, 0, n+1) {
    //     cout << pos[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    double ans = 0.0;
    REP(i, 1, n+1) {
      // cout << pos[n][i-1] << endl;
      ans += (pos[n][i] - pos[n][i-1]) * i;
    }
    printf("%.6f\n", ans);
  }
  return 0;
}
