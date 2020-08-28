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
int n, a, b, c;

void solve() {
  if (a + b - c > n || (a + b - c == 1 && n >= 2)) {
    printf("IMPOSSIBLE\n");
    return;
  } else if (n == 1) {
    printf("1\n");
  } else if (n == 2) {
    if (c == 2)
      printf("1 1\n");
    else if (a == 2)
      printf("1 2\n");
    else if (b == 2)
      printf("2 1\n");
  } else {
    // error case: 10 3 3 3
    // vector<int> ans(n, 1);
    // for (int i = 0; i < a - c; i++) ans[i] = 2;
    // for (int i = 0; i < b - c; i++) ans[n - 1 - i] = 2;
    // for (int i = 0; i < c; i++) ans[i + a - c] = 3;
    vector<int> ans;
    ans.reserve(n);
    for (int i = 0; i < a - c; i++) ans.push_back(2);
    for (int i = 0; i < c; i++) ans.push_back(3);
    for (int i = 0; i < b - c; i++) ans.push_back(2);
    int extra = n - (a + b - c);
    if (extra > 0) {
      ans.insert(ans.begin() + 1, extra, 1);
    }
    for (int i = 0; i < n; i++) {
      if (i) printf(" ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &a, &b, &c);
    // REP(i, 0, n) { scanf("%d", &a[i]); }
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
