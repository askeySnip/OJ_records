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

int n, k;
int m[100010];

bool check(int d) {
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    int dist = m[i] - m[i - 1];
    if (dist > d) {
      cnt += (dist - 1) / d;
    }
    if (cnt > k) return false;
  }
  return true;
}

void solve() {
  int l = 0, h = 1e9;
  while (l < h - 1) {
    int mid = (l + h) / 2;
    if (check(mid)) {
      h = mid;
    } else
      l = mid;
  }
  printf("%d\n", h);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%d", &n, &k);
    REP(i, 0, n) scanf("%d", &m[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
