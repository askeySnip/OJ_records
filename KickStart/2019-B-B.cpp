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
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 1e9;
const int mod = 1e9 + 7;

int n;
int s[110], e[110], l[110];
int idx[110];
int mem[110][10024];
int sum_s;

bool cmp(int a, int b) { return s[a] * l[b] < s[b] * l[a]; }

int dp(int time, int id) {
  if (mem[id][time] != -1) return mem[id][time];
  if (id == n) return 0;
  mem[id][time] = max(
      dp(time + s[idx[id]], id + 1) + max(0, e[idx[id]] - time * l[idx[id]]),
      dp(time, id + 1));
  return mem[id][time];
}

int solve() {
  REP(i, 0, n) idx[i] = i;
  sort(idx, idx + n, cmp);
  memset(mem, -1, sizeof mem);
  sum_s = 0;
  for (int i = 0; i < n; i++) {
    sum_s += s[i];
  }
  return dp(0, 0);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d%d%d", &s[i], &e[i], &l[i]);
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
