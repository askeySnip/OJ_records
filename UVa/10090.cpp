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
ll n;
ll c1, c2, n1, n2;

int extend_gcd(ll a, ll b, ll& x, ll& y) {
  int d = a;
  if(b != 0) {
    d = extend_gcd(b, a%b, y, x);
    y -= (a/b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

int main() {
  while(scanf("%lld", &n), n) {
    scanf("%lld %lld", &c1, &n1);
    scanf("%lld %lld", &c2, &n2);
    ll x, y, d;
    d = extend_gcd(n1, n2, x, y);
    ll l = ceil(-1.0*x*n/n2), h = floor(1.0*y*n/n1);
    if(n%d || l > h) printf("failed\n");
    else if(c1 * n2 >= c2 * n1) {
      x = x * n / d + n2 / d * l;
      y = y * n / d - n1 / d * l;
      printf("%lld %lld\n", x, y);
    }else {
      x = x * n / d + n2 / d * h;
      y = y * n / d - n1 / d * h;
      printf("%lld %lld\n", x, y);
    }

  }
  return 0;
}
