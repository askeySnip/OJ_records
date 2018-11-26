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

// struct
#define inf 1e9

// data


int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int a[100003];
  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  long long ans = 0;
  int h = 0;
  for(int i=0; i<n; i++) {
    if(a[i] == 0) continue;
    if(a[i] > h) h++;
    ans += a[i] - 1;
  }
  if(h != a[n-1]) ans -= (a[n-1]-h);
  printf("%I64d\n", ans);
  return 0;
}
