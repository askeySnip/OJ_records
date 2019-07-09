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
int mem[1003];
vi primes;
bitset<1003> bs;

void sieve() {
  bs.set(); bs[0] = bs[1] = 0;
  REP(i, 2, 1003) {
    primes.push_back(i);
    for(int j=i*i; j<1003; j+=i) bs[j] = 0;
  }
}

int sumDiv(int n) {
  int ans = 1;
  REP(i, 0, primes.size()) {
    if(primes[i] > n) break;
    if(n % primes[i] == 0) {
      int cnt = 0;
      while(n%primes[i] == 0) {cnt++; n/=primes[i];}
      ans *= (pow(primes[i], cnt+1) - 1) / (primes[i] - 1);
    }
  }
  return ans;
}

int main() {
  sieve();
  memset(mem, -1, sizeof mem);
  REP(i, 1, 1001) {
    int t = sumDiv(i);
    if(t < 1003) mem[t] = i;
  }
  int n, kase = 0;
  while(scanf("%d", &n), n) {
    printf("Case %d: %d\n", ++kase, mem[n]);
  }
  return 0;
}
