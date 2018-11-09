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
#define inf 1e9
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

// data
int n, m;
int maze[1024][1024];
int dis[1024][1024];
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d%d", &n, &m);
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        scanf("%d", &maze[i][j]);
        dis[i][j] = inf;
      }
    }
    priority_queue<pair<int, ii>, vector<pair<int, ii> >, greater<pair<int, ii> > > pq;
    pq.push(make_pair(maze[0][0], ii(0, 0)));
    //dis[0][0] = maze[0][0];
    while(!pq.empty()) {
      ii pos = pq.top().second;
      int v = pq.top().first;
      pq.pop();
      if(dis[pos.first][pos.second] != inf) continue;
      if(pos.first == n-1 && pos.second == m-1) {
        printf("%d\n", v);
        break;
      }
      dis[pos.first][pos.second] = v;
      for(int i=0; i<4; i++) {
        int tx = pos.first + dx[i], ty = pos.second + dy[i];
        if(tx >=0 && tx < n && ty >=0 && ty < m && dis[tx][ty] == inf) {
          pq.push(make_pair(v + maze[tx][ty], ii(tx, ty)));
        }
      }
    }
  }
  return 0;
}
