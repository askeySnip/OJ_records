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
typedef vector<pair<int, int>> vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

// struct
const double eps = 1e-12;

// data
int n, a, p;

int my_pow(int base, int e) {
  if (e == 1) return base % p;
  if (e % 2 == 1) {
    return (1LL * base * my_pow(base, e - 1)) % p;
  } else {
    return my_pow((1LL * base * base) % p, e / 2) % p;
  }
}

int solve() {
  REP(i, 1, n + 1) { a = my_pow(a, i); }
  return a;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &a, &n, &p);
    printf("Case #%d: %d\n", ++kase, solve());
    // solve();
  }

  return 0;
}
