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
typedef unsigned long long ull;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct

// data
int n, t;
ii ab[3010];
int mem[3010][3010];

int dp(int id, int tm) {
  if (id == n) return 0;
  if (tm >= t) return 0;
  if (mem[id][tm]) return mem[id][tm];
  int ret = max(dp(id + 1, tm + ab[id].first) + ab[id].second, dp(id + 1, tm));
  return mem[id][tm] = ret;
}

void solve() {
  sort(ab, ab + n);
  printf("%d\n", dp(0, 0));
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%d%d", &n, &t);
    REP(i, 0, n) { scanf("%d%d", &ab[i].first, &ab[i].second); }
    solve();
  }

  return 0;
}
