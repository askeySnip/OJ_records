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
  while(scanf("%d", &n), n != -1) {
    int a = n, r;
    int s = (int)sqrt(2*n);
    for(r=s; r>=1; r--) {
      if((2*n+r-r*r)%(2*r) == 0) {
        a = (2*n+r-r*r) / (2*r);
        break;
      }
    }
    printf("%d = %d + ... + %d\n", n, a, a+r-1);
  }
  return 0;
}
