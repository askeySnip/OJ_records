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
bitset<1000003> vist;

void generate_primes() {
  vist.set();
  vist[0] = vist[1] = 0;
  for(ll i=2; i<1000003; i++){
    if(vist[i]) {
      primes.push_back(int(i));
      for(ll j=i*i; j<1000003; j+=i) {
        vist[j] = 0;
      }
    }
  }
}

int main() {
  int n;
  generate_primes();
  while(scanf("%d", &n), n) {
    REP(i, 0, primes.size()) {
      if(vist[n - primes[i]]) {
        printf("%d = %d + %d\n", n, primes[i], n-primes[i]);
        break;
      }
    }
  }
  return 0;
}
