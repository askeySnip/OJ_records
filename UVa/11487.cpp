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
struct stats{
  int r, c, w;
  char last;
  stats(){}
  stats(int R, int C, int W, char L) : r(R), c(C), w(W), last(L) {}
};

int dirr[4] = {0, 0, -1, 1};
int dirc[4] = {1, -1, 0, 0};

// data
const int mod = 20437;
int v[11][11][27];
int dp[11][11][27][11*11*27];
char g[13][13];
int n;
char final;

bool inside(int i, int j) {
  return (i>=0 && i<n && j>=0 && j<n);
}

void bfs(int si, int sj) {
  memset(v, 0, sizeof v);
  memset(dp, 0, sizeof dp);
  dp[si][sj][0][0] = 1;
  queue<stats> q;
  q.push(stats(si, sj, 0, 'A'));
  while(!q.empty()) {
    int r = q.front().r, c = q.front().c, w = q.front().w;
    char last = q.front().last;
    q.pop();
    if(v[r][c][last-'A']) continue;
    v[r][c][last-'A'] = 1;
    if(g[r][c] == final) {
      printf("%d %d\n", w, dp[r][c][last-'A'][w]%mod);
      return;
    }
    int paths = dp[r][c][last-'A'][w];
    if(g[r][c] == last) g[r][c] = '.', last++;
    for(int i=0; i<4; i++) {
      int tr = r+dirr[i], tc = c+dirc[i];
      if(inside(tr, tc) && !v[tr][tc][last-'A'] && (g[tr][tc] == '.' || g[tr][tc] == last)){
        q.push(stats(tr, tc, w+1, last));
        dp[tr][tc][last-'A'][w+1] = (dp[tr][tc][last-'A'][w+1]%mod + paths%mod)%mod;
      }
    }
  }
  printf("Impossible\n");
}

int main() {
  int kase = 0;
  while(scanf("%d", &n), n) {
    int si, sj;
    final = 'A';
    for(int i=0; i<n; i++) {
      scanf("%s", g[i]);
      for(int j=0; j<n; j++) {
        if(g[i][j] == 'A') {
          si = i;
          sj = j;
        }else if(g[i][j]>='A' && g[i][j] <= 'Z'){
          final = max(final, g[i][j]);
        }
      }
    }
    //cout << final << endl;
    //cout << "sdfasdf" << endl;
    printf("Case %d: ", ++kase);
    bfs(si, sj);
  }
  return 0;
}
