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
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};

// data
int graph[2024][2024];
int vist[2024][2024];

int main() {
  int p;
  while(scanf("%d", &p), p) {
    int x, y;
    memset(graph, 0, sizeof graph);
    memset(vist, 0, sizeof vist);

    queue<pair<int, ii> > q;
    for(int i=0; i<p; i++) {
      scanf("%d%d", &x, &y);
      graph[x][y] = 1;
      q.push(make_pair(0, ii(x, y)));
    }
    scanf("%d", &p);
    for(int i=0; i<p; i++) {
      scanf("%d%d", &x, &y);
      graph[x][y] = 2;
    }
    int ans = -1;
    while(!q.empty()) {
      ii pos = q.front().second;
      int val = q.front().first;
      q.pop();
      if(vist[pos.first][pos.second]) continue;
      vist[pos.first][pos.second] = 1;
      if(graph[pos.first][pos.second] == 2) {
        ans = val;
        break;
      }
      for(int i=0; i<4; i++) {
        int tx = pos.first + dx[i], ty = pos.second + dy[i];
        if(tx>=0 && tx<2001 && ty >=0 && ty < 2001 && vist[tx][ty] == 0) {
          q.push(make_pair(val+1, ii(tx, ty)));
        }
      }
    }
    printf("%d\n", ans);
  }

  return 0;
}
