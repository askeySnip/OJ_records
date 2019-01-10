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
bitset<1000010> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i = 2; i<1000010; i++) {
    if(bs[i]) {
      primes.push_back((int)i);
      for(ll j=i*i; j<1000010; j+=i) bs[j] = 0;
    }
  }
}

int main() {
  ll n;
  sieve();
  while(scanf("%lld", &n), n) {
    ll a = 1;
    REP(i, 0, primes[i]) {
      if(primes[i] > n) break;
      ll t = primes[i];
      while(t*(ll)primes[i] <= n) t *= primes[i];
      a *= t;
      while(a%10 == 0) a/=10;
      a %= 1000000000;
    }
    printf("%d\n", (int)a%10);
  }
  return 0;
}
