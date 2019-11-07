/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <list>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)
const int mod = 1e9+7;

// data
ll r, c;

ll extend_gcd(ll a, ll b, ll& x, ll& y) {
  if(a == 0 && b == 0) return -1;
  if(!b) {
    x = 1, y = 0;
    return a;
  }
  ll ans = extend_gcd(b, a%b, y, x);
  y -= x * (a / b);
  return ans;
}

ll inv(ll a, ll mod) {
  ll x, y;
  ll d = extend_gcd(a, mod, x, y);
  if(d == 1) return (x + mod) % mod;
  else return -1;
}

ll solve() {
  r--;
  c--;
  if(r < c) swap(r, c);
  ll inv12 = inv(12, mod);
  ll ans = ((((2 * r - c + 1) * (c + 1))%mod) * (((c + 2) * c) % mod))%mod;
  ans = (ans * inv12)%mod;
  ans = (ans + mod) % mod;
  return ans;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld%lld", &r, &c);
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
