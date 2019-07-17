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
  int l, w, h, theta;
  while(scanf("%d%d%d%d", &l, &w, &h, &theta) == 4) {
    double t = tan(theta * acos(0) / 90) * l;
    if(t > h) {
      t = tan((90 - theta) * acos(0)/ 90) * h;
      printf("%.3f mL\n", h * t * 0.5 * w);
    }else {
      printf("%.3f mL\n", l * w * h - l * t * 0.5 * w);
    }
  }
  return 0;
}
