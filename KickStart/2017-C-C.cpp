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
const ll inf = 1e9;
const int mod = 1e9 + 7;

int n, q;
char a[3][60];
int s[3];
int cnt[4];

bool check(int i, int j, int k, int l) {
  int c1 = 0, c2 = 0;
  c1 += cnt[0] - i, c2 += cnt[0] - i;
  c1 += j, c2 += j;
  c1 += (cnt[2] - k), c2 += k;
  c1 += l, c2 += (cnt[3] - l);
  return c1 == s[0] && c2 == s[1];
}

int solve() {
  if (n == 1) {
    int cnt0 = 0, cnt1 = 0;
    REP(i, 0, q) {
      if (a[0][i] == a[1][i])
        cnt1++;
      else
        cnt0++;
    }
    if (s[0] >= cnt1) {
      return cnt1 + q - s[0];
    } else {
      return s[0] + q - cnt1;
    }
  } else {
    cnt[0] = cnt[1] = cnt[2] = cnt[3] = 0;
    REP(i, 0, q) {
      if (a[0][i] == a[1][i] && a[0][i] != a[2][i])
        cnt[0]++;
      else if (a[0][i] == a[1][i] && a[0][i] == a[2][i])
        cnt[1]++;
      else if (a[0][i] != a[1][i] && a[1][i] == a[2][i])
        cnt[2]++;
      else if (a[0][i] != a[1][i] && a[0][i] == a[2][i])
        cnt[3]++;
    }
    int ans = 0;
    REP(i, 0, cnt[0] + 1) {
      REP(j, 0, cnt[1] + 1) {
        REP(k, 0, cnt[2] + 1) {
          REP(l, 0, cnt[3] + 1) {
            if (check(i, j, k, l)) ans = max(ans, i + j + k + l);
          }
        }
      }
    }
    return ans;
  }
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  // t = 1;
  while (t--) {
    scanf("%d%d", &n, &q);
    REP(i, 0, n + 1) scanf("%s", a[i]);
    REP(i, 0, n) scanf("%d", &s[i]);
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }
  return 0;
}
