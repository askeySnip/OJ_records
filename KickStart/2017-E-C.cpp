/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define inf 1e9
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const double eps = 1e-12;

// struct
struct point {
  double x, y, z;
};

// data
point p[3];

double sq(double x) { return x * x; }

double dist(point& a, point& b) {
  return sqrt(sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z));
}

bool check(double r) {
  bool a = dist(p[0], p[1]) <= 2 * r;
  bool b = dist(p[1], p[2]) <= 2 * r;
  bool c = dist(p[0], p[2]) <= 2 * r;
  return (a && b) || (a && c) || (b && c);
}

double solve() {
  double max_x = -10000, min_x = 10000;
  REP(i, 0, 3) {
    max_x = max(max_x, p[i].x);
    min_x = min(min_x, p[i].x);
  }
  return (max_x - min_x) / 6.0;
}

int main() {
  int t, kase = 0;
  scanf("%d", &t);
  int l;
  while (t--) {
    REP(i, 0, 3) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
    printf("Case #%d: %.10f\n", ++kase, solve());
  }
  return 0;
}
