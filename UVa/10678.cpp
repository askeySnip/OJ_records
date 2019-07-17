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
  int n, d, l;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d%d", &d, &l);
    double a = (l - d) / 2.0 + d / 2.0;
    double b = sqrt(l*l - d*d) / 2.0;
    printf("%.3f\n", 2*acos(0) * a * b);
  }
  return 0;
}
