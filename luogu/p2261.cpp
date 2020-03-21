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
ll n, k;

int main() {
  cin >> n >> k;
  ll ans = n * k;
  for(ll l = 1, r; l<=n; l = r+1) {
    if(k/l) r = min(k/(k/l), n);
    else r = n;
    ans -= (k/l) * (r - l + 1) * (l + r) / 2;
  }
  printf("%lld\n", ans);
  return 0;
}
