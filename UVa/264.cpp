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
  while(scanf("%d", &n) == 1) {
    int r = sqrt(n*2);
    while(r*(r+1) < 2*n) r++;
    if(n == 1) printf("TERM 1 IS 1/1\n");
    else {
      int d = n - (r-1)*r/2;
      if(r&1) {
        printf("TERM %d IS %d/%d\n", n, r-d+1, d);
      } else {
        printf("TERM %d IS %d/%d\n", n, d, r-d+1);
      }
    }
  }
  return 0;
}
