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
vii twin_primes;
bitset<20000010> bs;

void generate_twin_primes() {
  twin_primes.push_back(ii(0, 0));
  bs.set();
  bs[0] = bs[1] = 0;
  int last = -1;
  for(ll i=2; i<20000010; i++) {
    if(bs[i]) {
      for(ll j=i*i; j<20000010; j+=i) {
        bs[j] = 0;
      }
      if(i - last == 2) twin_primes.push_back(ii(last, i));
      last = i;
    }
  }
}

int main() {
  int s;
  generate_twin_primes();
  while(scanf("%d", &s) == 1) {
    printf("(%d, %d)\n", twin_primes[s].first, twin_primes[s].second);
  }
  return 0;
}
