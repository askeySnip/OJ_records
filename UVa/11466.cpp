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
const int maxn = 10000010;
vi primes;
bitset<maxn> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<maxn; i++) {
    if(bs[i]) {
      primes.push_back(i);
      for(ll j = i*i; j<maxn; j+=i) bs[j] = 0;
    }
  }
}

int main() {
  ll n, tn;
  sieve();
  while(scanf("%lld", &n), n) {
    if(n < 0) n = -n;
    tn = n;
    ll lpd = -1, lpd2 = -1;
    REP(i, 0, primes.size()) {
      if(n < primes[i] || tn == primes[i]) break;
      if(n%primes[i] == 0) {
        if(primes[i] > lpd) lpd2 = lpd, lpd = primes[i];
        while(n%primes[i] == 0) n/=primes[i];
      }
    }
    if(n != 1 && n != tn && n > lpd) lpd2 = lpd, lpd = n;
    if(lpd2 != -1) printf("%lld\n", lpd);
    else printf("-1\n");
  }
  return 0;
}
