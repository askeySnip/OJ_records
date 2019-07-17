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


double getArea(double a, double b, double c) {
  double s = (a + b + c) * 0.5;
  return sqrt(s * (s - a) * (s - b) * (s - c) );
}

int main() {
  int a, b, c;
  while(scanf("%d%d%d", &a, &b, &c) == 3) {
    double areaTri = getArea(a, b, c);
    double r = a * b * c / (4.0 * areaTri);
    double areaBigCir = 2 * acos(0) * r * r;
    double rr = 2 * areaTri / (a + b + c);
    double areaSmlCir = 2 * acos(0) * rr * rr;
    printf("%.4f %.4f %.4f\n", areaBigCir - areaTri, areaTri - areaSmlCir, areaSmlCir);
  }
  return 0;
}
