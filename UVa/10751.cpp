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
int n;

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    scanf("%d", &n);
    double ans;
    if(n == 1) ans = 0.0;
    else if(n == 2) ans = 4.0;
    else {
      ans = 2.0 * n;
      ans += 2 * (n - 2);
      ans += (n-2)*(n-2) * sqrt(2);
    }
    printf("%.3f\n", ans);
    if(t) printf("\n");
  }
  return 0;
}
