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
#define EPS 1e-9
// data


int main() {
  int l, c, r1, r2;
  while(scanf("%d%d%d%d", &l, &c, &r1, &r2), l || c || r1 || r2) {
    if(l < c) swap(l, c);
    if(r1 < r2) swap(r1, r2);
    if(c < 2 * r1) printf("N\n");
    else if(l >= r1 * 2 + r2 * 2 && c >= 2 * r1) printf("S\n");
    else {
      double d = l - (r1 + r2);
      double t = sqrt((r1+r2) * (r1+r2) - d * d);
      if(fabs(c - t - r1 - r2) < EPS || c - t - r1 - r2 > 0.0) {
        printf("S\n");
      } else {
        printf("N\n");
      }
    }
  }
  return 0;
}
