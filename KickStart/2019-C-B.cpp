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

int r, c, k;
int v[400][400];
int maxlen[400][400];

int solve() {
  // memset(maxlen, 0, sizeof maxlen);
  REP(i, 0, r) {
    REP(j, 0, c) {
      int maxv = v[i][j], minv = v[i][j];
      maxlen[i][j] = 1;
      for (int p = j + 1; p < c; p++) {
        maxv = max(maxv, v[i][p]);
        minv = min(minv, v[i][p]);
        if (maxv - minv <= k)
          maxlen[i][j]++;
        else
          break;
      }
    }
  }
  vi s;
  s.push_back(-1);
  int ans = 0;
  REP(j, 0, c) {
    REP(i, 0, r) {
      while (s.back() != -1 && maxlen[s.back()][j] > maxlen[i][j]) {
        int v = maxlen[s.back()][j];
        s.pop_back();
        ans = max(ans, (i - s.back() - 1) * v);
      }
      s.push_back(i);
    }
    while (s.back() != -1) {
      int v = maxlen[s.back()][j];
      s.pop_back();
      ans = max(ans, (r - s.back() - 1) * v);
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &r, &c, &k);
    REP(i, 0, r) {
      REP(j, 0, c) { scanf("%d", &v[i][j]); }
    }
    printf("Case #%d: %d\n", ++kase, solve());
  }
  return 0;
}
