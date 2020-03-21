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
int n, m;
int a[66];
double f[66][66];

int main() {
  scanf("%d%d", &n, &m);
  REP(i, 0, m) scanf("%d", a + i);
  f[1][1] = 1.0;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      int p = (a[j] % i == 0) ? i : a[j] % i;
      for (int k = 1; k <= i - 1; k++) {
        ++p;
        if (p > i) p = 1;
        f[i][p] += f[i - 1][k] / m;
      }
    }
  }
  for (int i = 1; i < n; i++) {
    printf("%.2f%% ", f[n][i]*100);
  }
  printf("%.2f%%\n", f[n][n]*100);
  return 0;
}
