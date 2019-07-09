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
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data
char puzzle[130][130];
char word[130];
ii s, e;
int dr[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[8] = {1, -1, 0, 1, -1, 1, -1, 0};
int n;

bool check(int r, int c, int dir, int len) {
  int cnt = 0;
  REP(i, 0, len) {
    int tr = r+i*dr[dir], tc = c + i * dc[dir];
    if(tr<1 || tr >n || tc < 1 || tr > n || puzzle[tr][tc] != word[cnt]) return false;
    cnt++;
  }
  return true;
}
bool backtrack(int r, int c, int id, int len) {
  if(puzzle[r][c] != word[id]) return false;
  bool ret = false;
  REP(i, 0, 8) {
    ret |= check(r, c, i, len);
    if(ret) {
      e = ii(r + (len-1)*dr[i], c + (len-1)*dc[i]);
      break;
    }
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  REP(i, 1, n+1) {
    scanf("%s", puzzle[i]+1);
  }
  while(scanf("%s", word), word[0] != '0') {
    int len = strlen(word);
    bool f = false;
    REP(i, 1, n+1) {
      if(f) break;
      REP(j, 1, n+1) {
        if(backtrack(i, j, 0, len)) {
          f = true;
          s = ii(i, j);
          break;
        }
      }
    }
    if(f) printf("%d,%d %d,%d\n", s.first, s.second, e.first, e.second);
    else printf("Not found\n");
  }

  return 0;
}
