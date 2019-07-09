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
bitset<10010> bs;

void sieve() {
  bs.set(); bs[0] = bs[1] = 0;
  for(int i=2; i<10010; i++) {
    if(bs[i]) {
      primes.push_back(i);
      for(int j=i*i; j<10010; j+=i) bs[j] = 0;
    }
  }
}

int mu(int n) {
  int cnt = 0;
  REP(i, 0, primes.size()) {
    if(primes[i] > n) break;
    if(n % primes[i] == 0) {
      cnt++;
      int c = 0;
      while(n%primes[i] == 0) {n/=primes[i]; c++;}
      if(c > 1) return 0;
    }
  }
  if(n!=1) cnt++;
  return (cnt%2==0 ? 1 : -1);
}

int main() {
  sieve();
  int sum[1000003];
  memset(sum, 0, sizeof sum);
  sum[1] = 1;
  REP(i, 2, 1000001) {
    sum[i] = sum[i-1] + mu(i);
  }
  int n;
  while(scanf("%d", &n), n) {
    printf("%8d%8d%8d\n", n, sum[n]-sum[n-1], sum[n]);
  }
  return 0;
}
