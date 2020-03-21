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
const int mod = 20100403;

// struct

// data
int n, m;
ll fact[2000024], inv[2000024];

ll my_pow(ll base, int exp) {
  int ret = 1;
  while (exp) {
    if (exp & 1) ret = (ret * base) % mod;
    base = (base * base) % mod;
    exp >>= 1;
  }
  return ret;
}

ll C(int n, int p) {
  ll z = (fact[n] * inv[p]) % mod;
  return (z * inv[n - p]) % mod;
}

int main() {
  scanf("%d%d", &n, &m);
  if (m > n) {
    puts("0\n");
    return 0;
  }
  fact[0] = 1;
  for (int i = 1; i <= n + m; i++) fact[i] = (fact[i - 1] * i) % mod;
  inv[n + m] = my_pow(fact[n + m], mod - 2);
  for (int i = n + m - 1; i >= 0; i--) {
    inv[i] = (inv[i + 1] * (i + 1)) % mod;
  }
  printf("%lld\n", (C(n + m, m) - C(n + m, m - 1) + mod) % mod);
  return 0;
}
