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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b;
  printf("?");
  REP(i, 1, 101) {
    printf(" %d", i);
  }
  printf("\n");
  fflush(stdout);
  scanf("%d", &a);
  printf("?");
  REP(i, 1, 101) {
    printf(" %d", i * (1 << 7));
  }
  printf("\n");
  fflush(stdout);
  scanf("%d", &b);
  int ans = 0;
  ans |= ((a >> 7) << 7);
  ans |= (b % (1 << 7));
  printf("! %d\n", ans);
  return 0;
}
