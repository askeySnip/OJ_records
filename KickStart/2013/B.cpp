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
  int t;
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    double v, d;
    scanf("%lf %lf", &v, &d);
    double s = 9.8 * d / v / v;
    if(s > 1) s = 1;
    printf("Case #%d: %.7f\n", ++kase, asin(s) / 3.14159265358979 * 90);
  }
  return 0;
}
