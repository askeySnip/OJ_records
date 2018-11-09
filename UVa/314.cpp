/*
Id: leezhen
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
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

// data
int n, m;
int graph[52][52];
int b1, b2, e1, e2;
int vist[4][52][52];

int main() {
  while(scanf("%d %d", &n, &m), n || m) {
    memset(graph, 0, sizeof graph);
    memset(vist, 0, sizeof vist);
    int t;
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        scanf("%d", &t);
        if(t) graph[i][j] = graph[i+1][j+1] = graph[i+1][j] = graph[i][j+1] = 1;
      }
    }

    char direction[20];
    int dir = 0;
    scanf("%d %d %d %d %s", &b1, &b2, &e1, &e2, direction);
    if(direction[0] == 's') dir = 2;
    else if(direction[0] == 'n') dir = 0;
    else if(direction[0] == 'e') dir = 1;
    else dir = 3;
    queue<pair<ii, ii> > q;
    int ans = -1;
    q.push(make_pair(make_pair(dir, 0), make_pair(b1, b2)));
    int tr, tc;
    while(!q.empty()) {
      ii status = q.front().first;
      ii pos = q.front().second;
      q.pop();

      if(vist[status.first][pos.first][pos.second] == 1) continue;
      if(pos.first == e1 && pos.second == e2) {
        ans = status.second;
        break;
      }
      vist[status.first][pos.first][pos.second] = 1;
      for(int i=1; i<4; i++) {
        tr = pos.first + i*dr[status.first]; tc = pos.second + i*dc[status.first];
        if(graph[tr][tc]) break;
        if(tr > 0 && tr < n && tc > 0 && tc < m && vist[status.first][tr][tc] == 0) {
          q.push(make_pair(make_pair(status.first, status.second + 1), make_pair(tr, tc)));
        }
      }
      q.push(make_pair(make_pair((status.first+1)%4, status.second + 1), pos));
      q.push(make_pair(make_pair((status.first+4-1)%4, status.second + 1), pos));
    }
    printf("%d\n", ans);
  }
  return 0;
}
