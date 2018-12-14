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
  int a, b, v, A, s;
  while(scanf("%d %d %d %d %d", &a, &b, &v, &A, &s), a || b || v || A || s) {
    double vh = v * cos(A/180.0*M_PI), vv = v * sin(A/180.0*M_PI);
    double len_h = vh * s / 2.0, len_v = vv * s / 2.0;
    int hc = 0, vc = 0;
    if(len_h >= a/2.0) vc++;
    if(len_v >= b/2.0) hc++;
    len_h -= a/2.0; len_v -= b/2.0;
    if(len_h >= a) vc += int(len_h/a*1.0);
    if(len_v >= b) hc += int(len_v/b*1.0);
    printf("%d %d\n", vc, hc);
  }
  return 0;
}
