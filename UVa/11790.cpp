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

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
int main() {
  int t, n;
  int a[2048], val[2048];
  int inc[2048], des[2048];
  scanf("%d", &t);
  int kase = 0;
  while(t--) {
    scanf("%d", &n);
    memset(inc, 0, sizeof inc);
    memset(des, 0, sizeof des);
    for(int i=0; i<n; i++) {
      scanf("%d", &a[i]);
    }
    for(int i=0; i<n; i++) scanf("%d", &val[i]);
    for(int i=0; i<n; i++) {
      for(int j=0; j<i; j++) {
        if(a[i] > a[j]) inc[i] = max(inc[i], inc[j]);
        if(a[i] < a[j]) des[i] = max(des[i], des[j]);
      }
      inc[i] += val[i];
      des[i] += val[i];
    }
    int minc = 0, mdes = 0;
    for(int i=0; i<n; i++) {
      minc = max(minc, inc[i]);
      mdes = max(mdes, des[i]);
    }
    if(minc >= mdes) {
      printf("Case %d. Increasing (%d). Decreasing (%d).\n", ++kase, minc, mdes);
    }else {
      printf("Case %d. Decreasing (%d). Increasing (%d).\n", ++kase, mdes, minc);
    }
  }
  return 0;
}
