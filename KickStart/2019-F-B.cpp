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

int n, s;
ll A[50024];
int m[50024];

ll solve() {
  ll ans = 0;
  map<ll, int> ump;
  for (int i = 0; i < n; i++) {
    ump[A[i]]++;
  }
  for (int i = 0; i < n; i++) {
    vi ta;
    ll tmp = A[i];
    while (tmp % 1024) {
      ta.push_back(tmp % 1024);
      tmp >>= 10;
    }
    sort(ta.begin(), ta.end());
    int cnt = 0;
    for (int j = 1; j < (1 << ta.size()); j++) {
      ll code = 0;
      for (int k = 0; k < ta.size(); k++) {
        if (j & (1 << k)) {
          code <<= 10;
          code |= ta[k];
        }
      }
      cnt += ump[code];
    }
    ans += n - cnt;
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int c;
  int a[5];
  while (t--) {
    memset(A, 0, sizeof A);
    scanf("%d %d", &n, &s);
    REP(i, 0, n) {
      scanf("%d", &c);
      REP(j, 0, c) { scanf("%d", &a[j]); }
      sort(a, a + c);
      REP(j, 0, c) {
        A[i] <<= 10;
        A[i] |= a[j];
      }
    }
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
