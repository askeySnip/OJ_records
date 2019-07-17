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
  int n;
  int ax, ay, bx, by, cx, cy, dx, dy;
  int llx, lly, uux, uuy;
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    if(i) printf("\n");
    scanf("%d%d%d%d%d%d%d%d", &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy);
    llx = max(ax, cx);
    lly = max(ay, cy);
    uux = min(bx, dx);
    uuy = min(by, dy);
    if(llx < uux && lly < uuy) {
      printf("%d %d %d %d\n", llx, lly, uux, uuy);
    } else {
      printf("No Overlap\n");
    }
  }
  return 0;
}
