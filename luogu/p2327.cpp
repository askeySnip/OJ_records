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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n;
int a[10024];
int f[10024][10];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  for (int i = 0; i < (1 << 2); i++) {
    if (__builtin_popcount(i) == a[0]) {
      f[0][i] = 1;
    }
  }
  REP(i, 1, n - 1) {
    for (int j = 0; j < 8; j++) {
      if (__builtin_popcount(j) == a[i]) {
        f[i][j] = f[i - 1][j >> 1] + f[i - 1][j >> 1 | 4];
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < 8; j++) {
    if (__builtin_popcount(j & 3) == a[n - 1]) {
      ans += f[n - 2][j];
    }
  }
  printf("%d\n", ans);
  return 0;
}
