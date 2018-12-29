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
  int t, n;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    ll ans = 0;
    int m = sqrt(n*1.0);
    int i;
    for(i=1; i<=m; i++) {       // for(int i=1; i*i<=n; i++) will cause TLE!XS
      ans += i * (n/i - n/(i+1));
      // if(i != n/i) ans += (n/i) * (n/(n/i-1) - i + 1);
    }
    for(i = n/(m+1); i>=1; i--) {
      ans += n/i;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
