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
  for(ll i = 2; i<maxn; i++) {
    if(bs[i]) {
      for(ll j = i*i; j<maxn; j+=i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}

bool isPrime(int n) {
  if(n < maxn) return bs[n];
  int m = sqrt(n*1.0);
  REP(i, 0, primes.size()) {
    if(primes[i] > m) break;
    if(n % primes[i] == 0) return false;
  }
  return true;
}

int main() {
  ll l, u;
  sieve();
  while(scanf("%lld %lld", &l, &u) == 2) {
    ll last = 0;
    ii min_dis = ii(0, maxn), max_dis = ii(0, 0);
    ll i = l;
    while(!isPrime(i)) i++;
    last = i++;
    for(; i<=u; i++) {
      if(isPrime(i)) {
        if(i - last > max_dis.second - max_dis.first) {
          max_dis = ii(last, i);
        }
        if(i - last < min_dis.second - min_dis.first) {
          min_dis = ii(last, i);
        }
        last = i;
      }
    }
    if(min_dis.first == 0) printf("There are no adjacent primes.\n");
    else {
      printf("%d,%d are closest, %d,%d are most distant.\n", min_dis.first, min_dis.second, max_dis.first, max_dis.second);
    }
  }
  return 0;
}
