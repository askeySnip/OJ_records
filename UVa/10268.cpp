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
  int x;
  while(scanf("%d", &x) == 1) {
    int t;
    ll ans = 0;
    vi a;
    while(scanf("%d", &t)) {
      a.push_back(t);
      if(getchar() == '\n') break;
    }
    reverse(a.begin(), a.end());
    ll base = 1;
    REP(i, 1, a.size()) {
      ans += base * a[i] * i;
      base *= x;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
