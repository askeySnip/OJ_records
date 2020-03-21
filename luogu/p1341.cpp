/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n;
int dis[150][150];
int deg[150];
vi ans;

void dfs(int u) {
  for(int i=0; i<150; i++) {
    if(dis[u][i]) {
      dis[u][i]--;
      dis[i][u]--;
      dfs(i);
    }
  }
  ans.push_back(u);
}


int main() {
  int n;
  scanf("%d", &n);
  char s[5];
  REP(i, 0, n) {
    scanf("%s", s);
    dis[s[0]][s[1]]++;
    dis[s[1]][s[0]]++;
    deg[s[0]]++;
    deg[s[1]]++;
  }
  int cnt = 0, st = 0;
  for(int i=0; i<150; i++) {
    if(deg[i]&1) {
      cnt++;
      if(!st) st = i;
    }
  }
  if(cnt && cnt != 2) {
    printf("No Solution\n");
    return 0;
  }
  if(!st) {
    for(int i=0; i<150; i++) {
      if(deg[i]) {
        st = i;
        break;
      }
    }
  }
  dfs(st);
  if(ans.size() < n+1) {
    printf("No Solution\n");
    return 0;
  }
  for(int i=ans.size()-1; i>=0;i--) {
    printf("%c", ans[i]);
  }
  puts("\n");
  return 0;
}
