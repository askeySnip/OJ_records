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
bitset<10000010> bs;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<10000010; i++) {
    if(bs[i]) {
      primes.push_back(i);
      for(ll j = i*i; j<10000010; j+=i) bs[j] = 0;
    }
  }
}

int num_factor(int n) {
  int ret = 1;
  REP(i, 0, primes.size()) {
    if(primes[i] > n) break;
    int power = 0;
    while(n%primes[i]==0) {
      power++;
      n/=primes[i];
    }
    ret *= (power * 2 + 1);
  }
  if(n!=1) ret*=3;
  ret/=2;
  ret+=1;
  return ret;
}

int main() {
  int n;
  sieve();
  while(scanf("%d", &n), n) {
    int t = num_factor(n);
    printf("%d %d\n", n, t);
  }
  return 0;
}
