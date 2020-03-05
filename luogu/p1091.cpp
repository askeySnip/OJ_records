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
int t[110];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &t[i]);
  vi dp1(n, 0);
  vi stk{t[0]};
  REP(i, 1, n) {
    auto it = lower_bound(stk.begin(), stk.end(), t[i]) - stk.begin();
    dp1[i] = it;
    if (it == stk.size())
      stk.push_back(t[i]);
    else
      stk[it] = t[i];
  }
  reverse(t, t + n);
  stk.clear(), stk.push_back(t[0]);
  int ans = dp1[n - 1] + 1;
  REP(i, 1, n) {
    int it = lower_bound(stk.begin(), stk.end(), t[i]) - stk.begin();
    ans = max(ans, it + 1 + dp1[n - 1 - i]);
    if (it == stk.size())
      stk.push_back(t[i]);
    else
      stk[it] = t[i];
  }
  printf("%d\n", n - ans);
  return 0;
}
