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
int r, n;
int a[1024];

int main() {
  while(scanf("%d %d", &r, &n), r != -1 || n != -1) {
    REP(i, 0, n) scanf("%d", &a[i]);
    sort(a, a+n);
    int ans = 0;
    for(int i=0; i<n; ) {
      ans++;
      int t = a[i] + r, ii = i;
      while(a[i] <= t) i++;
      i--;
      if(i != ii) t = a[i] + r;
      while(a[i] <= t) i++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
