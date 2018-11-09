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
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

// data
int r, c;
int graph[1024][1024];
int sr, sc, desr, desc;
int vist[1024][1024];

int main() {
  int rows, n, row, col;
  while(scanf("%d %d", &r, &c), r || c) {
    scanf("%d", &rows);
    memset(graph, 0, sizeof graph);
    memset(vist, 0, sizeof vist);

    for(int i=0; i<rows; i++) {
      scanf("%d %d",&row, &n);
      for(int j=0; j<n; j++) {
        scanf("%d", &col);
        graph[row][col] = 1;
      }
    }
    scanf("%d %d", &sr, &sc);
    scanf("%d %d", &desr, &desc);
    queue<pair<int, ii> > q;
    q.push(make_pair(0, ii(sr, sc)));
    int ans = 0;
    while(!q.empty()) {
      pair<int, ii> p = q.front(); q.pop();
      if(vist[p.second.first][p.second.second]) continue;
      vist[p.second.first][p.second.second] = 1;
      if(p.second.first == desr && p.second.second == desc) {
        ans = p.first;
        break;
      }
      for(int i=0; i<4; i++) {
        int tr = p.second.first + dr[i], tc = p.second.second + dc[i];
        if(tr >= 0 && tr < r && tc >=0 && tc < c && graph[tr][tc] == 0) {
          q.push(make_pair(p.first+1, ii(tr, tc)));
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
