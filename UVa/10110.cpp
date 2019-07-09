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
vi primes;
bitset<100010> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i = 2; i<100010; i++) {
    if(bs[i]) {
      primes.push_back(i);
      for(ll j = i*i; j<100010; j+=i) bs[j] = 0;
    }
  }
}

int numDiv(ll n) {
  int ret = 1;
  REP(i, 0, primes.size()) {
    if(primes[i] > n) break;
    if(n % primes[i] == 0) {
      int cnt = 0;
      while(n%primes[i] == 0) {
        cnt++;
        n/=primes[i];
      }
      ret *= (cnt+1);
    }
  }
  if(n != 1) ret *= 2;
  return ret;
}

int main() {
  // sieve();
  ll n;
  while(scanf("%lld", &n), n) {
    // ll t = numDiv(n);
    // if(t&1) printf("yes\n");
    // else printf("no\n");
    ll t = sqrt(n*1.0);
    if(t*t == n) printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
