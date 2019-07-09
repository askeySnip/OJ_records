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
char grid[6][6];
char word[20];
int len;
int dr[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int score(int len) {
  // cout << "len" << len << endl;
  if(len < 5) return 1;
  else if(len == 5) return 2;
  else if(len == 6) return 3;
  else if(len == 7) return 5;
  else return 11;
}

bool check(int r, int c, int id) {
  if(r < 0 || r >= 4 || c < 0 || c >= 4 || grid[r][c] != word[id]) return false;
  if(id == len - 1) return true;
  char ch = grid[r][c];
  grid[r][c] = '.';
  bool ret = false;
  REP(i, 0, 8) {
    ret |= check(r+dr[i], c+dc[i], id+1);
  }
  grid[r][c] = ch;
  return ret;
}
bool solve() {
  REP(i, 0, 4) {
    REP(j, 0, 4) {
      if(check(i, j, 0)) return true;
    }
  }
  return false;
}
int main() {
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    REP(i, 0, 4) {
      scanf("%s", grid[i]);
    }
    int n;
    scanf("%d", &n);
    int ans = 0;
    REP(i, 0, n) {
      scanf("%s", word);
      len = strlen(word);
      if(solve()) {
        ans += score(len);
      }
    }
    printf("Score for Boggle game #%d: %d\n", ++kase, ans);
  }
  return 0;
}
