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
int a[510][510];

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      scanf("%d", &a[i][j]);
      a[j][i] = a[i][j];
    }
    a[i][i] = -1;
  }
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    sort(a[i] + 1, a[i] + n + 1);
    ans = max(ans, a[i][n - 1]);
  }
  printf("1\n%d\n", ans);
  return 0;
}
