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
  int n, s;
  scanf("%d%d", &n, &s);
  int ans = 0;
  int last = min(n, s);
  while(s) {
    last = min(last, s);
    s -= last;
    ans ++;
  }
  printf("%d\n", ans);
  return 0;
}
