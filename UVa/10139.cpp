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
int n, m;
vi primes;
bitset<100010> bs;
map<int, int> n_mp, m_mp;

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

int solve() {
  for(int i=0; i<(int)primes.size() && primes[i]*primes[i] <= m; i++) {
    if(m%primes[i] == 0) {
      int cnt1 = 0;
      while(m%primes[i] == 0) {m/=primes[i]; cnt1++;}
      int cnt2 = 0;
      ll tmp = primes[i];
      while(tmp <= n) {
        cnt2 += n/tmp;
        tmp *= primes[i];
      }
      if(cnt2 < cnt1) return 0;
    }
  }
  if(m != 1) {
    if(n < m) return 0;
  }
  return 1;
}

int main() {
  primes.clear();
  sieve();
  // REP(i, 0, 10) cout << primes[i] << endl;
  while(scanf("%d %d", &n, &m) == 2) {
    int mm = m, nn = n;
    if(solve()) printf("%d divides %d!\n", mm, nn);
    else printf("%d does not divide %d!\n", mm, nn);
  }
  return 0;
}
