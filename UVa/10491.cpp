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
  int ncows, ncars, nshows;
  while(scanf("%d %d %d", &ncows, &ncars, &nshows) == 3) {
    double p = 1.0 * ncows / (ncows + ncars) * ncars / (ncows + ncars - nshows - 1);
    p += 1.0 * ncars / (ncows + ncars) * (ncars - 1) / (ncows + ncars - nshows - 1);
    printf("%.5f\n", p);
  }
  return 0;
}
