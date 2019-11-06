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

int n, k;
ll p;
vii cnst[110];
ll mem[110][1 << 16];

bool ok(int mask, int i, vii& r) {
  for (auto e : r) {
    int len = i - e.first + 1;
    if (__builtin_popcount(mask) - __builtin_popcount(mask >> len) != e.second)
      return false;
  }
  return true;
}

ll dp(int mask, int i) {
  if (mem[i][mask] != -1) return mem[i][mask];
  if (!ok(mask, i, cnst[i])) {
    return mem[i][mask] = 0;
  }
  if (i == n) return mem[i][mask] = 1;
  int next_mask = (mask << 1) & 0xffff;
  ll ret = dp(next_mask, i + 1);
  if (ret < p) {
    ret += dp(next_mask | 1, i + 1);
  }
  // if(ret > p) ret = p;
  return mem[i][mask] = ret;
}

string solve() {
  memset(mem, -1, sizeof mem);
  dp(0, 0);
  int mask = 0;
  string ans;
  for (int i = 1; i <= n; i++) {
    mask = (mask << 1) & 0xffff;
    if (mem[i][mask] >= p)
      ans = ans + '0';
    else {
      p -= mem[i][mask];
      mask |= 1;
      ans = ans + '1';
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int a, b, c;
  while (t--) {
    REP(i, 0, 110) cnst[i].clear();
    scanf("%d%d%lld", &n, &k, &p);
    REP(i, 0, k) {
      scanf("%d%d%d", &a, &b, &c);
      cnst[b].push_back(ii(a, c));
    }
    printf("Case #%d: %s\n", ++kase, solve().c_str());
  }
  return 0;
}
