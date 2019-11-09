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
int e, n;
int s[1024];

int solve() {
  sort(s, s + n);
  int ans = 0;
  int f = 0, t = n - 1;
  int cur = 0;
  while (f <= t) {
    while (f <= t && s[f] < e) {
      cur++;
      e -= s[f++];
    }
    ans = max(ans, cur);
    if (t >= f && cur) {
      e += s[t--];
      cur -= 1;
    } else {
      break;
    }
  }
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &e, &n);
    REP(i, 0, n) scanf("%d", &s[i]);
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }

  return 0;
}
