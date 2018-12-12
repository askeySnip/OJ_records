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
  int t, n;
  scanf("%d", &t);
  int kase = 0;
  int a[20];
  while (t--) {
    scanf("%d", &n);
    REP(i, 0, n) scanf("%d", &a[i]);
    printf("Case %d: %d\n", ++kase, a[n/2]);
  }
  return 0;
}
