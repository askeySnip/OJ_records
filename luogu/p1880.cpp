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
int n;
int a[210];
int sum[210];
int m1[210][210], m2[210][210];
int dp1(int s, int e) {
  if (s == e) return 0;
  if (m1[s][e] != -1) return m1[s][e];
  int ret = inf;
  for (int i = s; i < e; i++) {
    ret = min(ret, dp1(s, i) + dp1(i + 1, e) + sum[e + 1] - sum[s]);
  }
  return m1[s][e] = ret;
}
int dp2(int s, int e) {
  if (s == e) return 0;
  if (m2[s][e] != -1) return m2[s][e];
  int ret = 0;
  for (int i = s; i < e; i++) {
    ret = max(ret, dp2(s, i) + dp2(i + 1, e) + sum[e + 1] - sum[s]);
  }
  return m2[s][e] = ret;
}

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  REP(i, 0, n) a[i + n] = a[i];
  sum[0] = 0;
  REP(i, 0, 2 * n + 1) sum[i + 1] = sum[i] + a[i];
  memset(m1, -1, sizeof m1);
  memset(m2, -1, sizeof m2);
  int ans1 = inf, ans2 = 0;
  REP(i, 0, n) {
    ans1 = min(ans1, dp1(i, i + n - 1));
    ans2 = max(ans2, dp2(i, i + n - 1));
  }
  printf("%d\n%d\n", ans1, ans2);
  return 0;
}
