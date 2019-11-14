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
int n, m;
int a[200010];
int maxa, maxps;
int b[200010];

void solve() {
  if (maxa > maxps) {
    printf("-1\n");
    return;
  }
  for (int i = n - 1; i > 0; i--) {
    b[i] = max(b[i], b[i + 1]);
  }
  int i = 0;
  int ans = 0;
  while (i < n) {
    int cnt = 1;
    int cur = a[i];
    while (i < n && b[cnt] >= cur) {
      i++;
      cnt++;
      cur = max(cur, a[i]);
    }
    ans++;
  }
  printf("%d\n", ans);
}

int main() {
  int k, kase = 0;
  scanf("%d", &k);
  // k = 1;
  while (k--) {
    REP(i, 0, n + 1) b[i] = 0;  // use rep instead memset(memset will TLE)
    maxa = maxps = 0;
    scanf("%d", &n);
    REP(i, 0, n) {
      scanf("%d", &a[i]);
      maxa = max(maxa, a[i]);
    }
    scanf("%d", &m);
    int p, s;
    REP(i, 0, m) {
      scanf("%d%d", &p, &s);
      maxps = max(maxps, p);
      b[s] = max(b[s], p);
    }
    solve();
  }

  return 0;
}
