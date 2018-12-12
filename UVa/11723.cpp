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
  int r, n;
  int kase = 0;
  while(scanf("%d %d", &r, &n), r || n) {
    int ans = -1;
    REP(i, 0, 27) {
      if(r <= n + n * i) {
        ans = i;
        break;
      }
    }
    if (ans != -1) printf("Case %d: %d\n", ++kase, ans);
    else printf("Case %d: impossible\n", ++kase);
  }
  return 0;
}
