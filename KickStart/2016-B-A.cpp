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

// struct
#define mp make_pair
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int mod = 1e9 + 7;
const double eps = 1e-14;
const ll llinf = 1e14;

// data
int l, r;

ll solve() {
  int n = min(l, r);
  return 1LL * (1 + n) * n / 2;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &l, &r);
    printf("Case #%d: %lld\n", ++kase, solve());
  }
  return 0;
}
