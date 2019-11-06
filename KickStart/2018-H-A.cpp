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

int n, p;
char forb[110][60];

bool check(int i, int j) {
  int len = strlen(forb[i]);
  REP(k, 0, len) {
    if (forb[i][k] != forb[j][k]) return false;
  }
  return true;
}

ll solve() {
  ll ans = (1LL << n);
  int used[110];
  REP(i, 0, p) used[i] = 1;
  REP(i, 0, p) {
    REP(j, 0, p) {
      if (i == j) continue;
      int leni = strlen(forb[i]), lenj = strlen(forb[j]);
      if (leni == lenj) continue;
      if (leni < lenj) {
        if (check(i, j)) used[j] = 0;
      } else {
        if (check(j, i)) used[i] = 0;
      }
    }
  }
  REP(i, 0, p) {
    if (used[i]) {
      ans -= (1LL << (n - strlen(forb[i])));
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &p);
    REP(i, 0, p) scanf("%s", forb[i]);
    printf("Case #%d: %lld\n", ++kase, solve());
    // solve();
  }
  return 0;
}
