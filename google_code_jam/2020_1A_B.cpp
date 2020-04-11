/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <climits>
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
typedef vector<pair<int, int> > vii;
typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;

void solve() {
  if (n <= 500) {
    REP(i, 1, n + 1) { printf("%d 1\n", i); }
    return;
  }
  int tn = n - 30, tot = 0;
  int l = 1, level = 1;
  while (tn) {
    if (tn & 1) {
      if (l) {
        REP(i, 1, level + 1) printf("%d %d\n", level, i);
      } else {
        for (int i = level; i >= 1; i--) printf("%d %d\n", level, i);
      }
      tot += (1 << (level - 1));
      l = 1 - l;
    } else {
      if (l) {
        printf("%d %d\n", level, 1);
      } else {
        printf("%d %d\n", level, level);
      }
      tot += 1;
    }
    level++;
    tn /= 2;
  }
  REP(i, 0, n - tot) {
    if (l)
      printf("%d 1\n", i + level);
    else
      printf("%d %d\n", i + level, i + level);
  }
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d", &n);
    printf("Case #%d:\n", ++kase);
    solve();
  }
  return 0;
}
