/*
ID: leezhen
TASK: practice
LANG: C++11
*/
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;

// struct

// data
int n;
int a[33];

int main() {
  scanf("%d", &n);
  REP(i, 0, n) scanf("%d", &a[i]);
  REP(i, 0, n) {
    if (a[i] == 0) {
      if (i % 2) {
        printf("YES\n");
        return 0;
      }
      break;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] == 0) {
      if ((n - 1 - i) % 2) {
        printf("YES\n");
        return 0;
      }
      break;
    }
  }
  printf("NO\n");
  return 0;
}
