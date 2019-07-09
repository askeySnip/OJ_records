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


int main() {
  int n;
  scanf("%d", &n);
  char msg[10][100];
  char ans[100];
  while(n--) {
    int c = 0;
    REP(i, 0, 10) {
      scanf("%s", msg[i]);
    }
    int m = strlen(msg[0]) - 2;
    REP(j, 1, m+1) {
      int t = 0;
      REP(i, 1, 9) {
        if(msg[i][j] == '\\') {
          t |= (1 << (i-1));
        }
      }
      ans[c++] = t;
    }
    ans[c] = '\0';
    printf("%s\n", ans);
  }
  return 0;
}
