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
ll n;
vi primes;
bitset<1000100> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i < 1000100; i++) {
    if (bs[i]) {
      for (ll j = i * i; j < 1000100; j += i) bs[j] = 0;
      primes.push_back((int)i);
    }
  }
}

vi primeFactors() {
  vi factors;
  ll pf_idx = 0, pf = primes[pf_idx];
  ll tn = n;
  while (pf * pf <= tn) {
    if (tn % pf == 0) {
      factors.push_back(pf);
      while (tn % pf == 0) tn /= pf;
    }
    pf_idx++;
    pf = primes[pf_idx];
  }
  if (tn != 1) factors.push_back(tn);
  return factors;
}

void solve() {
  sieve();
  vi factors = primeFactors();
  if (factors.size() == 1) {
    printf("%d\n", factors[0]);
    return;
  }
  printf("%d\n", 1);
}

int main() {
  int k, kase = 0;
  // scanf("%d", &k);
  k = 1;
  while (k--) {
    scanf("%lld", &n);
    solve();
  }

  return 0;
}
