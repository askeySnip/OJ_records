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
const int N = 100000;
vi primes;
bitset<N> vist;
int n;

void product_primes() {
  REP(i, 2, N+1) {
    if(!vist[i]) {
      primes.push_back(i);
      for(int j=i<<1; j<=N; j+=i) {
        vist[j] = true;
      }
    }
  }
}

int sum_digits(int m) {
  int ret = 0;
  while(m) {
    ret += m%10;
    m/=10;
  }
  return ret;
}

int sum_prime_digits(int m) {
  int ret = 0;
  REP(i, 0, primes.size()) {
    while(m%primes[i] == 0) ret += sum_digits(primes[i]), m/=primes[i]; // notice the duplicate condition
    if(primes[i] > m) break;
  }
  if(m!=1) ret += sum_digits(m);
  return ret;
}

bool is_prime(int m) {
  REP(i, 0, primes.size()) {
    if(m <= primes[i]) continue; // notice should check first.
    if(m%primes[i] == 0) return 0;
  }
  return 1;
}

int find_next(int m) {
  REP(i, m+1, 2e9) {
    if(is_prime(i)) continue;
    if(sum_digits(i) == sum_prime_digits(i)) return i;
  }
  return 0;
}

int main() {
  product_primes();
  //cout << primes[0] << endl;
  //cout << is_prime(2) << endl;
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    printf("%d\n", find_next(n));
  }
  return 0;
}
