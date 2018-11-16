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

// struct
#define inf 1e6

// data
int n;
int r;
int dist[103][103];

int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    scanf("%d%d", &n, &r);
    for(int i=0; i<n; i++) {
      for(int j=0; j<n; j++) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = inf;
      }
    }
    int a, b;
    for(int i=0; i<r; i++) {
      scanf("%d%d", &a, &b);
      dist[a][b] = dist[b][a] = 1;
    }
    scanf("%d%d", &a, &b);
    for(int k=0; k<n; k++) {
      for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }
    int ans = 0;
    for(int i=0; i<n; i++) {
      if(dist[a][i] != inf && dist[i][b] != inf) {
        ans = max(ans, dist[a][i] + dist[i][b]);
      }
    }
    printf("Case %d: %d\n", ++kase, ans);
  }
  return 0;
}
