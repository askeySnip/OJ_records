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
#define inf 1e6;

// data
int dist[103][103];
int nodes[103];

int main() {
  int a, b;
  int kase = 0;
  while(scanf("%d%d", &a, &b), a || b) {
    for(int i=1; i<101; i++) {
      for(int j=1; j<101; j++) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = inf;
      }
    }
    dist[a][b] = 1; nodes[a] = nodes[b] = 1;
    memset(nodes, 0, sizeof nodes);
    while(scanf("%d%d", &a, &b), a || b) {
      dist[a][b] = 1;
      nodes[a] = nodes[b] = 1;
    }
    for(int k=1; k<101; k++) {
      for(int i=1; i<101; i++) {
        for(int j=1; j<101; j++) {
          if(dist[i][j] > dist[i][k] + dist[k][j]) dist[i][j] = dist[i][k] + dist[k][j];
        }
      }
    }

    int tot = 0, n = 0;
    for(int i=1; i<101; i++) {
      if(!nodes[i]) continue;
      for(int j=1; j<101; j++) {
        if(i == j || nodes[j] == 0) continue;
        tot += dist[i][j];
        n++;
      }
    }
    printf("Case %d: average length between pages = %.3f clicks\n", ++kase, (double)(tot*1.0/n));
  }
  return 0;
}
