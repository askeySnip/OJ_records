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

double uu(int v, int u) {
  return sqrt(u*u - v*v);
}

int main() {
  int t;
  double d, v, u;
  int kase = 0;
  scanf("%d", &t);
  while (t--) {
    scanf("%lf%lf%lf", &d, &v, &u);
    if (u <= v || v == 0) {     // notice : when v == 0 , there is only on way to go. also, don't try to check if f1 == f2 with maybe the float is not equal in binary store.
      printf("Case %d: can't determine\n", ++kase);
    }else {
      double f1 = d / u;
      double f2 = d / (uu(v, u));
      printf("Case %d: %.3f\n", ++kase, f2 - f1);
    }
  }
  return 0;
}
