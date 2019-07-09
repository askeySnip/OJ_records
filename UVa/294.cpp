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
      for(ll j=i*i; j<100010; j+=i) bs[j] = 0;
    }
  }
}

int divisors(int t) {
  int ret = 1;
  REP(i, 0, primes.size()) {
    if(primes[i] > t) break;
    if(t % primes[i] == 0) {
      int cnt = 0;
      while(t%primes[i] == 0) {t/=primes[i]; cnt++;}
      ret *= (cnt+1);
    }
  }
  if(t != 1) ret *= 2;
  return ret;
}

void solve(int l, int h) {
  ii ans = ii(0, 0);
  REP(i, l, h+1) {
    int d = divisors(i);
    if(ans.second < d) ans = ii(i, d);
  }
  printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, h, ans.first, ans.second);
}

int main() {
  int n;
  scanf("%d", &n);
  sieve();
  int l, h;
  while(n--) {
    scanf("%d %d", &l, &h);
    solve(l, h);
  }
  return 0;
}
