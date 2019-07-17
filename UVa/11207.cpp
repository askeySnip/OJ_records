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
  int n, a, b, id;
  double ma;
  while(scanf("%d", &n), n) {
    ma = 0.0;
    for(int i=1; i<=n; i++) {
      scanf("%d%d", &a, &b);
      if(a < b) swap(a, b);
      double t = max(min(a/4.0, b*1.0), min(a/2.0, b/2.0));
      if(t > ma) {
        ma = t;
        id = i;
      }
    }
    printf("%d\n", id);
  }
  return 0;
}
