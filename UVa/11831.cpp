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
int n, m, s;
char graph[103][103];
int dirc[4] = {0, 1, 0, -1};
int dirr[4] = {1, 0, -1, 0};
int main() {
  while(scanf("%d%d%d", &n, &m, &s), n||m||s) {
    int x = -1, y = -1, dir;
    for(int i=0; i<n; i++) {
      scanf("%s", graph[i]);
      if(x<0 && y < 0)
      for(int j=0; j<m; j++) {
        if(graph[i][j] == 'N' || graph[i][j] == 'S' || graph[i][j] == 'L' || graph[i][j] == 'O'){
          x = i; y = j;
          if(graph[i][j] == 'N') dir = 2;
          else if(graph[i][j] == 'S') dir = 0;
          else if(graph[i][j] == 'L') dir = 1;
          else dir = 3;
          break;
        }
      }
    }
    getchar();
    int ans = 0;
    for(int i=0; i<s; i++) {
      char c = getchar();
      if(c == 'D') dir = (dir+4-1)%4;
      else if(c == 'E') dir = (dir+1)%4;
      else {
        x += dirr[dir];
        y += dirc[dir];
        if(x<0 || x>=n || y<0 || y>=m) {x-=dirr[dir];y-=dirc[dir];}
        if(graph[x][y] == '*') {ans++; graph[x][y] = '.';}
        else if(graph[x][y] == '#') x-=dirr[dir], y-=dirc[dir];
      }
    }
    printf("%d\n", ans);
  }
}
