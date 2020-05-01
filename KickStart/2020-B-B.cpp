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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

int n;
ll d;
ll x[1010];

bool check(ll s) {
  REP(i, 0, n) {
    ll t1 = s / x[i] * x[i];
    if(t1 < s) t1 += x[i];
    ll t2 = d / x[i] * x[i];
    s = t1;
    if(t1 > t2) return false;
  }
  return true;
}

void solve() {
  ll l = 0, h = d + 1;
  while(l < h - 1) {
    ll mid = (l + h) / 2;
    if(check(mid)) l = mid;
    else h = mid;
    // cout << l << " " << h << endl;
  }
  printf("%lld\n", l);
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);

  while (t--) {
    scanf("%d%lld", &n, &d);
    REP(i, 0, n) scanf("%lld", &x[i]);
    printf("Case #%d: ", ++kase);
    solve();
  }
  return 0;
}
