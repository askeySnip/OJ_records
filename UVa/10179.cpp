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
  for(ll i=2; i<100010; i++) {
    if(bs[i]) {
      primes.push_back((int)i);

    }
  }
}

int main() {
  int n;
  sieve();
  while(scanf("%d", &n), n) {
    int nn = n;
    REP(i, 0, primes.size()) {
      if(primes[i] > n) break;
      if(n % primes[i] == 0) nn = nn - nn/primes[i];
      while(n % primes[i] == 0) n /= primes[i];
    }
    if(n!=1) nn = nn - nn/n;
    printf("%d\n", nn);
  }
  return 0;
}
