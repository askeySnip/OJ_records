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
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, a, b;
int num[1024];
int f[1024][10007];
int main() {
  scanf("%d", &n);
  REP(i, 1, n + 1) scanf("%d %d", &a, &b), num[i] = a - b;
  REP(i, 0, n + 5) REP(j, 0, 10007) f[i][j] = inf;
  int base = 5001;
  f[0][base] = 0;
  REP(i, 1, n + 1) {
    REP(j, -5000, 5001) {
      f[i][j + base] =
          min(f[i - 1][j - num[i] + base], f[i - 1][j + num[i] + base] + 1);
    }
  }
  REP(i, 0, 5001) {
    int ans = min(f[n][i + base], f[n][-i + base]);
    if (ans != inf) {
      printf("%d\n", ans);
      return 0;
    }
  }
  return 0;
}
