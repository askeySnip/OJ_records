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
const double eps = 1e-12;

// data
int n;
int sq[110];
int mem[110][10010];

int dp(int id, int rem) {
  if (mem[id][rem]) return mem[id][rem];
  if (rem == 0) return 0;
  if (sq[id] > rem) return inf;
  int ret = inf;
  for (int i = 0; i * sq[id] <= rem; i++) {
    ret = min(ret, i + dp(id + 1, rem - sq[id] * i));
  }
  return mem[id][rem] = ret;
}

int solve() {
  memset(mem, 0, sizeof mem);
  return dp(1, n);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  REP(i, 0, 110) sq[i] = i * i;
  while (t--) {
    scanf("%d", &n);
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }

  return 0;
}
