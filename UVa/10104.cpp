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
#define inf 1e18
#define REP(i, a, b) for(int i = int(a); i < int(b); i++)

// data

ll extend_gcd(ll a, ll b, ll& x, ll& y) {
  ll d = a;
  if(b != 0) {
    d = extend_gcd(b, a%b, y, x);
    y -= (a/b)*x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

int main() {
  ll a, b, x, y, d;
  while(scanf("%lld %lld", &a, &b) == 2) {
    d = extend_gcd(a, b, x, y);
    double pointa = -1.0 * x / b, pointb = 1.0 * y / a;
    ll ansx, ansy, ans, pa, pb;
    if(pointa >= pointb) {
      pa = ceil(pointa), pb = floor(pointb);
    } else {
      pa = floor(pointb), pb = ceil(pointb);
    }
    ansx = x + b * pb, ansy = y - a * pb;
    ans = abs(ansx) + abs(ansy);
    if(ans > abs(x+b*pa)+abs(y-a*pa)) {
      ans = abs(x+b*pa) + abs(y-a*pa);
      ansx = x+b*pa, ansy = y-a*pa;
    } else if(ans == abs(x+b*pa) + abs(y-a*pa)) {
      if(ansx >= ansy) ansx = x+b*pa, ansy = y-a*pa;
    }
    printf("%lld %lld %lld\n", ansx, ansy, d);
  }
  return 0;
}
