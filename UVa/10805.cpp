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

// data
int n, m;
int graph[600][600];

int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    scanf("%d %d", &n, &m);
    int N = n + m, node = n;
    for(int i=0; i<N; i++) {
      for(int j=i+1; j<N; j++) {
        if(i!=j) graph[i][j] = graph[j][i] = inf;
        else graph[i][j] = 0;
      }
    }
    int a, b;
    for(int i=0; i<m; i++) {
      scanf("%d %d", &a, &b);
      graph[a][node] = graph[node][a] = 1;
      graph[b][node] = graph[node][b] = 1;
      node++;
    }
    for(int k=0; k<N; k++) {
      for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
          graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
        }
      }
    }
    int ans = inf;
    for(int i=0; i<N; i++) {
      int v[2] = {};
      for(int j=0; j<n; j++) {
        if(graph[i][j] > v[1]) v[1] = graph[i][j];
        if(v[1] > v[0]) swap(v[0], v[1]);
      }
      ans = min(ans, v[0]+v[1]);
    }
    printf("Case #%d:\n", ++kase);
    printf("%d\n\n", ans/2);
  }
  return 0;
}
