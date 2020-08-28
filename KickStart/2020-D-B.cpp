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
int k;
int a[10010];
int f[10010][4];

void solve() {
  memset(f, 0, sizeof f);
  REP(i, 1, k) {
    if (a[i] > a[i - 1]) {
      f[i][0] =
          min(f[i - 1][0], min(f[i - 1][1], min(f[i - 1][2], f[i - 1][3]))) + 1;
      f[i][1] =
          min(f[i - 1][0], min(f[i - 1][1], min(f[i - 1][2], f[i - 1][3])) + 1);
      f[i][2] =
          min(min(f[i - 1][0], f[i - 1][1]), min(f[i - 1][2], f[i - 1][3]) + 1);
      f[i][3] =
          min(min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])), f[i - 1][3] + 1);
    } else if (a[i] == a[i - 1]) {
      f[i][0] =
          min(f[i - 1][0], min(f[i - 1][1], min(f[i - 1][2], f[i - 1][3])) + 1);
      f[i][1] =
          min(f[i - 1][1], min(f[i - 1][0], min(f[i - 1][2], f[i - 1][3])) + 1);
      f[i][2] =
          min(f[i - 1][2], min(f[i - 1][0], min(f[i - 1][1], f[i - 1][3])) + 1);
      f[i][3] =
          min(f[i - 1][3], min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])) + 1);
    } else {
      f[i][0] =
          min(min(f[i - 1][0] + 1, f[i - 1][1]), min(f[i - 1][2], f[i - 1][3]));
      f[i][1] = min(f[i - 1][0] + 1,
                    min(f[i - 1][1] + 1, min(f[i - 1][2], f[i - 1][3])));
      f[i][2] = min(min(f[i - 1][0], f[i - 1][1]) + 1,
                    min(f[i - 1][2] + 1, f[i - 1][3]));
      f[i][3] =
          min(min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2])), f[i - 1][3]) + 1;
    }
  }
  printf("%d\n",
         min(min(f[k - 1][0], f[k - 1][1]), min(f[k - 1][2], f[k - 1][3])));
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &k);
    REP(i, 0, k) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
