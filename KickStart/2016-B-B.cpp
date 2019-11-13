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
typedef vector<pair<int, int>> vii;
typedef long long ll;

// struct
#define mp make_pair
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;
const double eps = 1e-14;
const ll llinf = 1e14;

// data
int a, b, k;
ll n;
ll cnta[100010], cntb[100010];

int my_pow(int base, int e) {
  if (e == 0) return 1 % k;
  if (e == 1) return base % k;
  if (e % 2 == 1) {
    return (1LL * base * my_pow(base, e - 1)) % k;
  } else {
    return my_pow((1LL * base * base) % k, e / 2);
  }
}

ll solve() {
  memset(cnta, 0, sizeof cnta);
  memset(cntb, 0, sizeof cntb);
  ll substrc = 0;
  REP(i, 0, k) {
    int ta = my_pow(i, a), tb = my_pow(i, b);
    ll ads = n / k + (n % k >= i);
    if (i == 0) ads -= 1;
    cnta[ta] += ads;
    cntb[tb] += ads;
    cnta[ta] %= mod;
    cntb[tb] %= mod;
    if ((ta + tb + k) % k == 0) substrc += ads, substrc %= mod;
  }
  ll ans = 0;
  REP(i, 1, k) {
    ans += (cnta[i] * cntb[k - i]) % mod;
    ans %= mod;
  }
  ans += (cnta[0] * cntb[0]) % mod;
  // cout << cnta[0] << " " << cntb[0] << endl;
  ans %= mod;
  ans = ans + mod - substrc;
  ans %= mod;
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%lld%d", &a, &b, &n, &k);
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
