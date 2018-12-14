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
  int n;
  while(scanf("%d", &n), n) {
    if (n == 1) {
      printf("1\n");
    } else {
      n--;
      int base = 1;
      while(n > base) {
        n -= base;
        base *= 2;
      }
      printf("%d\n", n * 2);
    }
  }
  return 0;
}
