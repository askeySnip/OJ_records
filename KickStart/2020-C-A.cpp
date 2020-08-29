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
int n, k;
int a[200010];

void solve() {
  int kk = k;
  int ans = 0;
  REP(i, 0, n) {
    if (a[i] != kk) kk = k;
    if (a[i] == kk) {
      --kk;
      if (kk == 0) {
        ++ans;
        kk = k;
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
