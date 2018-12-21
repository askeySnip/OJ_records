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
  int n, m, c;
  while(scanf("%d %d %d", &n, &m, &c), n || m || c) {
    // ll ans = 0;
    // ll t = min(n, m) - 7L;
    // if(c==0) t--;
    // ans = t * ll((n+m)/2) - (7 + 6 + t) * t / 2;
    // if((n&1) && (m&1) && c == 1) ans -= t/2;
    // if((n&1) == 0 && (m&1) == 0 && c == 0) ans -= t/2;
    // //if(c) ans += 1L;
    // printf("%lld\n", ans);
    printf("%d\n",((n-7+c)/2)*((m-6)/2) + ((n-6-c)/2)*((m-7)/2));
  }
  return 0;
}
