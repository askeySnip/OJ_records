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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n, m, q;
ll a[500024], t;
int cnt[500024];

int main() {
  int x;
  scanf("%d%d%d", &n, &m, &q);
  memset(cnt, 0, sizeof cnt);
  REP(i, 1, n+1) {
    scanf("%d", &x);
    a[i] = 1ll * (cnt[x]++) * m + x;
  }
  sort(a+1, a+1+n);
  for(int i=1; i<=n; i++) a[i] -= i;
  REP(i, 0, q) {
    scanf("%lld", &t);
    t -= n;
    if(t > a[n]) t+=n;
    else {
      t += lower_bound(a+1, a+1+n, t) - a - 1;
    }
    printf("%lld\n", (t-1)%m+1);
  }
  return 0;
}
