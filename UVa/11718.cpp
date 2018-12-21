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

// data

ll mypow(ll base, ll p, ll mod) {
  if(p == 0) return 1L;
  if(p == 1) return base%mod;
  base %= mod;
  if(p&1) return (base*(mypow(base, p-1L, mod)%mod))%mod;
  else return mypow((base*base)%mod, p/2, mod)%mod;
}

int main() {
  int t;
  scanf("%d", &t);
  ll n, k, mod;
  int kase = 0;
  while(t--) {
    scanf("%lld %lld %lld", &n, &k, &mod);
    ll sum = 0L, a;
    REP(i, 0, n) {
      scanf("%lld", &a);
      sum += a;
    }
    // printf("%lld\n", (mypow(n, k-1, mod)%mod * (sum%mod) * (k%mod))%mod);
    ll pw = mypow(n, k-1, mod)%mod;
    printf("Case %d: %lld\n", ++kase, ((pw*(sum%mod)%mod)*(k%mod))%mod);
  }
  return 0;
}
