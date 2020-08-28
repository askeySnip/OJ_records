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
int a[210000];

void solve() {
  int ans = 1, diff = a[0] - a[1], cnt = 1;
  REP(i, 1, n) {
    if (diff == a[i - 1] - a[i]) {
      ++cnt;
    } else {
      ans = max(ans, cnt);
      cnt = 2;
      diff = a[i - 1] - a[i];
    }
  }
  ans = max(ans, cnt);
  printf("%d\n", ans);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) { scanf("%d", &a[i]); }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
