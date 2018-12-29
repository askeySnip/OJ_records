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
bitset<100011> bs;
int ans[2000];

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  for(ll i=2; i<100011; i++){
    if(bs[i]) {
      primes.push_back(i);
      for(ll j=i*i; j<100011; j+=i) bs[i] = 0;
    }
  }
}

int main() {
  int g, n, id;
  sieve();
  while(scanf("%d", &g), g) {
    n = g;
    id = 0;
    if(g < 0) ans[id++]=-1, g=-g;
    REP(i, 0, primes.size()) {
      if(primes[i] > g) break;
      while(g%primes[i] == 0) {g/=primes[i]; ans[id++]=primes[i];}
    }
    if(g!=1) ans[id++]=g;
    printf("%d = ", n);
    REP(i, 0, id) {
      if(i) printf(" x ");
      printf("%d", ans[i]);
    }
    printf("\n");
  }
  return 0;
}
