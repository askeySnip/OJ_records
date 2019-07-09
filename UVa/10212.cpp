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


int main() {
  ll n, m;
  while(scanf("%lld %lld", &n, &m) == 2) {
    ll t = 1;
    for(ll i=0; i<m; i++) {
      t*=(n-i);
      while(t%10==0) t/=10;
      t%=100000000;
    }
    printf("%d\n", (int)t%10);
  }
  return 0;
}
