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
typedef long long ll;

// struct
#define inf 1e9
#define REP(i, a, b) for(int i=int(a); i<int(b); i++)
// data
int n;
int a[100024];

int main() {
  scanf("%d", &n);
  for(int i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, a+n);
  int f = 0;
  for(int i=0; i<n; i++) {
    f = f ^ ((a[i] - i) % 2);
  }
  int cnt = 0;
  for(int i=1; i<n; i++) {
    if(a[i] == a[i-1]) {
      cnt++;
      if(a[i] == 0 || (i > 1 && a[i-2] == a[i]-1)) cnt++;
    }
  }
  if(cnt > 1) f = false;
  if(f) printf("sjfnb\n");
  else printf("cslnb\n");
  return 0;
}
