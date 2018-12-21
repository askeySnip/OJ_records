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
char X[15];
double x, y;

int main() {
  while(gets(X)) {
    y = strlen(X)+1;
    sscanf(X, "%lf", &x);
    while(true) {
      double f = log2(x) + y * log2(10);
      double t = log2(x+1) + y * log2(10);
      //cout << ceil(f) << " " << floor(t) << endl;
      //cout << f << " " << t << endl;
      if(ceil(f)-floor(t) <= 10e-9) {
        printf("%.0f\n", ceil(f));
        break;
      }
      y++;
    }
  }
  return 0;
}
