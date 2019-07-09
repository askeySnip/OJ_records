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
int a, c;

void sieve() {
  bs.set();
  bs[0] = bs[1] = 0;
  REP(i, 2, 10010) {
    if(bs[i]) {
      primes.push_back(i);
      for(int j=i*i; j<10010; j+=i) bs[j] = 0;
    }
  }
}

int solve() {
  int ans = 1;
  REP(i, 0, primes.size()) {
    if(primes[i] > a) break;
    if(a%primes[i] == 0) {
      int cnt1 = 0;
      while(c%primes[i]==0) {c/=primes[i]; cnt1++;}
      int cnt2 = 0;
      while(a%primes[i] == 0) {a/=primes[i]; cnt2++;}
      if(cnt1 < cnt2) return -1;
      if(cnt2 < cnt1) ans *= (pow(primes[i], cnt1));
    }
  }
  if(a != 1) {
    if(c%a) return -1;
    c/=a;
    a = 1;
  }
  if(a != c) ans *= c;
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  sieve();
  while(t--) {
    scanf("%d %d", &a, &c);
    int ans = solve();
    if(ans < 0) printf("NO SOLUTION\n");
    else printf("%d\n", ans);
  }
  return 0;
}
