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
ll n, a, b;

ll f(ll x) {
  return ( ( (a%n)*( (x%n)*(x%n) %n) )%n + b%n )%n;
}

int main() {
  while(scanf("%lld", &n), n) {
    scanf("%lld %lld", &a, &b);
    ll t = 0L, h = 0L;
    t = f(t); h = f(f(h));
    while(t != h) {
      t = f(t);
      h = f(f(h));
    }
    h = 0L;
    while(h != t) {
      h = f(h);
      t = f(t);
    }
    h = f(t);
    ll c = 1L;
    while(h != t) {
      h = f(h);
      c++;
    }
    printf("%lld\n", n - c);
  }
  return 0;
}
