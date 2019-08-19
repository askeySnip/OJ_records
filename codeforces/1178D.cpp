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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
vi primes;
bitset<10010> vist;
int n;

void sieve() {
  vist.set();
  vist[0] = vist[1] = 0;
  for(int i=2; i<10010; i++) {
    if(vist[i]) {
      for(int j=i*i; j<10010; j+=i) vist[j] = 0;
      primes.push_back(i);
    }
  }
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  sieve();
  int m = *lower_bound(primes.begin(), primes.end(), n);
  cout << m << '\n';
  cout << "1 " << n << '\n';
  for(int i=0; i<n-1; i++) {
    cout << i+1 << ' ' << i+2 << '\n';
  }
  for(int i=0; i<m-n; i++) {
    cout << i+1 << ' ' << i+1 + n/2 << '\n';
  }
  return 0;
}
