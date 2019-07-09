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
int m, n, k;
char puzzle[60][60];
char word[100];
int dr[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[8] = {1, -1, 0, 1, -1, 0, 1, -1};

bool inside(int r, int c) {
  if(r < m && r >= 0 && c < n && c >= 0) return true;
  return false;
}

bool check_dir(int r, int c, int len, int i) {
  REP(j, 0, len) {
    if(!inside(r + j * dr[i], c + j * dc[i]) || puzzle[r + j * dr[i]][c + j * dc[i]] != word[j]) return false;
  }
  return true;
}

bool check(int r, int c, int len) {
  bool ret = false;
  REP(i, 0, 8) {
    ret |= check_dir(r, c, len, i);
    if(ret) return true;
  }
  return false;
}
void solve() {
  int len = strlen(word);
  REP(i, 0, m) {
    REP(j, 0, n) {
      if(check(i, j, len)) {
        printf("%d %d\n", i+1, j+1);
        return;
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d %d", &m, &n);
    REP(i, 0, m) {
      scanf("%s", puzzle[i]);
      REP(j, 0, n) {
        puzzle[i][j] = toupper(puzzle[i][j]);
      }
    }
    scanf("%d", &k);
    REP(i, 0, k) {
      scanf("%s", word);
      int len = strlen(word);
      REP(j, 0, len) {
        word[j] = toupper(word[j]);
      }
      solve();
    }
    if(t) printf("\n");
  }
  return 0;
}
