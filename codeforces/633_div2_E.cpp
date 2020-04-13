/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
ll n;
ll b, c;

void cacl(ll a) {
  ll now = 1;
  b = c = 0;
  while (a) {
    if (a % 4 == 1) {
      b += 2 * now;
      c += 3 * now;
    } else if (a % 4 == 2) {
      b += 3 * now;
      c += now;
    } else if (a % 4 == 3) {
      b += now;
      c += 2 * now;
    }
    a /= 4;
    now *= 4;
  }
}

void solve() {
  if (n <= 3) {
    printf("%lld\n", n);
    return;
  }
  ll x = (n - 1) / 3 + 1;
  ll a = 1, now = 1;
  while (x > now) {
    x -= now;
    a <<= 2;
    now <<= 2;
  }
  a += x - 1;
  cacl(a);
  if (n % 3 == 1)
    printf("%lld\n", a);
  else if (n % 3 == 2)
    printf("%lld\n", b);
  else
    printf("%lld\n", c);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    solve();
  }
  return 0;
}
