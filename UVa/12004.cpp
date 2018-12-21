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
  int kase = 0, t;
  ll n;
  scanf("%d", &t);
  while(t--) {
    scanf("%lld", &n);
    ll ans = n * (n-1);
    ans /= 2;
    printf("Case %d: ", ++kase);
    if(ans&1L) printf("%lld/2\n", ans);
    else printf("%lld\n", ans/2L);
  }
  return 0;
}
