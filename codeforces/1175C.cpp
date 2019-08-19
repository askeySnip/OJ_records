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
int n, k;
int a[200024];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int kase;
  cin >> kase;
  while(kase--) {
    cin >> n >> k;
    REP(i, 0, n) cin >> a[i];
    if(k == 0) {
      printf("%d\n", a[0]);
      continue;
    }
    int f = 0, t = k;
    int ans = a[0], dis = inf;
    while(t < n) {
      int dk = (a[t] - a[f] + 1) / 2;
      if(dk < dis) {
        ans = (a[t] + a[f]) / 2;
        dis = dk;
      }
      f++; t++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
